/*
 * Copyright (c) 2020 jMonkeyEngine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of 'jMonkeyEngine' nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package com.jme3.bullet;

import com.jme3.bullet.collision.PhysicsCollisionObject;
import com.jme3.bullet.objects.MultiBodyCollider;
import com.jme3.math.Vector3f;
import java.util.Collection;
import java.util.Map;
import java.util.TreeSet;
import java.util.concurrent.ConcurrentHashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import jme3utilities.Validate;

/**
 * A Bullet-JME physics space with its own btMultiBodyDynamicsWorld.
 *
 * @author Stephen Gold
 */
public class MultiBodySpace extends PhysicsSpace {
    // *************************************************************************
    // constants and loggers

    /**
     * message logger for this class
     */
    final public static Logger logger2
            = Logger.getLogger(MultiBodySpace.class.getName());
    // *************************************************************************
    // fields

    /**
     * copy of the constraint solver used
     */
    private SolverType solverType = SolverType.Dantzig;
    /**
     * map multibody IDs to added objects
     */
    final private Map<Long, MultiBody> multiBodyMap
            = new ConcurrentHashMap<>(64);
    // *************************************************************************
    // constructors

    /**
     * Instantiate a MultiBodySpace. Must be invoked on the designated physics
     * thread.
     *
     * @param worldMin the desired minimum coordinates values (not null,
     * unaffected, default=-10k,-10k,-10k)
     * @param worldMax the desired minimum coordinates values (not null,
     * unaffected, default=10k,10k,10k)
     * @param broadphaseType which broadphase collision-detection algorithm to
     * use (not null)
     */
    public MultiBodySpace(Vector3f worldMin, Vector3f worldMax,
            BroadphaseType broadphaseType) {
        super(worldMin, worldMax, broadphaseType);
    }

    /**
     * Instantiate a MultiBodySpace. Must be invoked on the designated physics
     * thread.
     *
     * @param worldMin the desired minimum coordinates values (not null,
     * unaffected, default=-10k,-10k,-10k)
     * @param worldMax the desired minimum coordinates values (not null,
     * unaffected, default=10k,10k,10k)
     * @param broadphaseType which broadphase collision-detection algorithm to
     * use (not null)
     * @param solverType which multibody constraint solver to use (not null)
     */
    public MultiBodySpace(Vector3f worldMin, Vector3f worldMax,
            BroadphaseType broadphaseType, SolverType solverType) {
        super(worldMin, worldMax, broadphaseType);
        Validate.nonNull(solverType, "solver type");
        this.solverType = solverType;
    }
    // *************************************************************************
    // new methods exposed

    /**
     * Count the multibodies in this space.
     *
     * @return the count (&ge;0)
     */
    public int countMultiBodies() {
        long spaceId = getSpaceId();
        int count = getNumMultibodies(spaceId);
        assert count == multiBodyMap.size();

        return count;
    }

    /**
     * Enumerate multibodies that have been added to this space and not yet
     * removed.
     *
     * @return a new collection of pre-existing instances (not null)
     */
    public Collection<MultiBody> getMultiBodyList() {
        return new TreeSet<>(multiBodyMap.values());
    }

    /**
     * Access the MultiBodySpace <b>running on this thread</b>. For parallel
     * physics, this can be invoked from the OpenGL thread.
     *
     * @return the pre-existing MultiBodySpace running on this thread
     */
    public static MultiBodySpace getMultiBodySpace() {
        return (MultiBodySpace) physicsSpaceTL.get();
    }
    // *************************************************************************
    // PhysicsSpace methods

    /**
     * Add the specified object to this space.
     *
     * @param object the object to add (not null)
     */
    @Override
    public void add(Object object) {
        Validate.nonNull(object, "object");

        if (object instanceof MultiBody) {
            addMultiBody((MultiBody) object);
        } else {
            super.add(object);
        }
    }

    /**
     * Test whether the specified collision object is added to this space.
     *
     * @param pco the object to search for (not null, unaffected)
     * @return true if currently added, otherwise false
     */
    @Override
    public boolean contains(PhysicsCollisionObject pco) {
        boolean result = false;

        if (pco instanceof MultiBodyCollider) {
            MultiBodyCollider collider = (MultiBodyCollider) pco;
            for (MultiBody multiBody : multiBodyMap.values()) {
                result = multiBody.contains(collider);
                if (result) {
                    break;
                }
            }

        } else {
            result = super.contains(pco);
        }

        return result;
    }

    /**
     * Must be invoked on the designated physics thread.
     */
    @Override
    protected void create() {
        long nativeId = createMultiBodySpace2(getWorldMin(null),
                getWorldMax(null), getBroadphaseType().ordinal(), 0);
        assert nativeId != 0L;
        logger2.log(Level.FINE, "Created {0}.", this);

        assert getWorldType(nativeId) == 2 // BT_DISCRETE_DYNAMICS_WORLD (!)
                : getWorldType(nativeId);
        initThread(nativeId);
        initSolverInfo();
    }

    /**
     * Test whether this space is empty.
     *
     * @return true if empty, otherwise false
     */
    @Override
    public boolean isEmpty() {
        boolean result = super.isEmpty();
        result = result && multiBodyMap.isEmpty();

        return result;
    }

    /**
     * Enumerate collision objects that have been added to this space and not
     * yet removed.
     *
     * @return a new collection of pre-existing instances (not null)
     */
    @Override
    public Collection<PhysicsCollisionObject> getPcoList() {
        Collection<PhysicsCollisionObject> result = super.getPcoList();
        for (MultiBody multiBody : multiBodyMap.values()) {
            Collection<MultiBodyCollider> pcos = multiBody.listColliders();
            result.addAll(pcos);
        }

        return result;
    }

    /**
     * Remove the specified object from this space.
     *
     * @param object the object to remove, or null
     */
    @Override
    public void remove(Object object) {
        if (object == null) {
            return;
        }

        if (object instanceof MultiBody) {
            removeMultiBody((MultiBody) object);
        } else {
            super.remove(object);
        }
    }
    // *************************************************************************
    // private methods

    /**
     * Add the specified MultiBody and all its colliders.
     *
     * @param multiBody (not null)
     */
    private void addMultiBody(MultiBody multiBody) {
        long multiBodyId = multiBody.nativeId();
        if (multiBodyMap.containsKey(multiBodyId)) {
            logger2.log(Level.WARNING, "{0} is already added to {1}.",
                    new Object[]{multiBody, this});
            return;
        }

        multiBodyMap.put(multiBodyId, multiBody);
        logger2.log(Level.FINE, "Adding {0} to {1}.",
                new Object[]{multiBody, this});

        long spaceId = getSpaceId();
        addMultiBody(spaceId, multiBodyId);
    }

    /**
     * Remove the specified MultiBody and all its colliders.
     *
     * @param multiBody (not null)
     */
    private void removeMultiBody(MultiBody multiBody) {
        long multiBodyId = multiBody.nativeId();
        if (!multiBodyMap.containsKey(multiBodyId)) {
            logger2.log(Level.WARNING, "{0} does not exist in {1}.",
                    new Object[]{multiBody, this});
            return;
        }
        logger2.log(Level.FINE, "Removing {0} from {1}.",
                new Object[]{multiBody, this});
        multiBodyMap.remove(multiBodyId);
        long spaceId = getSpaceId();
        removeMultiBody(spaceId, multiBodyId);
    }
    // *************************************************************************
    // native methods

    native private void addMultiBody(long spaceId, long multiBodyId);

    native private void addMultiBodyConstraint(long spaceId, long constraintId);

    native private long createMultiBodySpace2(Vector3f minVector,
            Vector3f maxVector, int broadphaseType, int solverType);

    native private int getNumMultibodies(long spaceId);

    native private int getNumMultiBodyConstraints(long spaceId);

    native private void removeMultiBody(long spaceId, long multiBodyId);

    native private void removeMultiBodyConstraint(long spaceId,
            long constraintId);
}
