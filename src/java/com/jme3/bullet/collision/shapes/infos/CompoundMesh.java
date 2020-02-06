/*
 * Copyright (c) 2019 jMonkeyEngine
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
package com.jme3.bullet.collision.shapes.infos;

import com.jme3.math.Vector3f;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import jme3utilities.Validate;

/**
 * A scalable mesh that combines multiple indexed meshes. Based on Bullet's
 * btTriangleIndexVertexArray.
 *
 * @author Stephen Gold sgold@sonic.net
 */
public class CompoundMesh {
    // *************************************************************************
    // constants and loggers

    /**
     * message logger for this class
     */
    final public static Logger logger
            = Logger.getLogger(CompoundMesh.class.getName());
    // *************************************************************************
    // fields

    /**
     * component meshes
     */
    private ArrayList<IndexedMesh> submeshes = new ArrayList<>(4);
    /**
     * Unique identifier of the btTriangleIndexVertexArray. The constructor sets
     * this to a non-zero value.
     */
    private long nativeId = 0L;
    /**
     * copy of scale factors: one for each local axis (default=(1,1,1)) TODO
     * privatize
     */
    protected Vector3f scale = new Vector3f(1f, 1f, 1f);
    // *************************************************************************
    // constructors

    /**
     * Instantiate an empty mesh.
     */
    public CompoundMesh() {
        createEmpty();
    }
    // *************************************************************************
    // new methods exposed

    /**
     * Add a submesh to this mesh.
     *
     * @param submesh (not null, alias created)
     */
    final public void add(IndexedMesh submesh) {
        Validate.nonNull(submesh, "submesh");

        submeshes.add(submesh);
        long submeshId = submesh.nativeId();
        addIndexedMesh(nativeId, submeshId);
    }

    /**
     * Count how many triangles are in this mesh.
     *
     * @return the count (&ge;0)
     */
    public int countTriangles() {
        int numTriangles = 0;
        for (IndexedMesh submesh : submeshes) {
            numTriangles += submesh.countTriangles();
        }

        assert numTriangles >= 0 : numTriangles;
        return numTriangles;
    }

    /**
     * Count how many vertices are in this mesh.
     *
     * @return the count (&ge;0)
     */
    public int countVertices() {
        int numVertices = 0;
        for (IndexedMesh submesh : submeshes) {
            numVertices += submesh.countVertices();
        }

        assert numVertices >= 0 : numVertices;
        return numVertices;
    }

    /**
     * Copy the scale factors.
     *
     * @param storeResult storage for the result (modified if not null)
     * @return the scale factor for each local axis (either storeResult or a new
     * vector, not null)
     */
    public Vector3f getScale(Vector3f storeResult) {
        Vector3f result = (storeResult == null) ? new Vector3f() : storeResult;
        assert checkScale(result);
        result.set(scale);

        return result;
    }

    /**
     * Read the ID of the btTriangleIndexVertexArray.
     *
     * @return the unique identifier (not zero)
     */
    public long nativeId() {
        assert nativeId != 0L;
        return nativeId;
    }

    /**
     * Alter the scale factors.
     *
     * @param scale the desired scale factor for each local axis (not null, no
     * negative component, unaffected, default=(1,1,1))
     */
    public void setScale(Vector3f scale) {
        assert nativeId != 0L;

        setScaling(nativeId, scale.x, scale.y, scale.z);
        logger.log(Level.FINE, "Scaled CompoundMesh {0}",
                Long.toHexString(nativeId));
        this.scale.set(scale);
    }
    // *************************************************************************
    // Object methods

    /**
     * Finalize this mesh just before it is destroyed. Should be invoked only by
     * a subclass or by the garbage collector.
     *
     * @throws Throwable ignored by the garbage collector
     */
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        logger.log(Level.FINE, "Finalizing CompoundMesh {0}",
                Long.toHexString(nativeId));
        finalizeNative(nativeId);
    }
    // *************************************************************************
    // private methods

    /**
     * Compare Bullet's scale factors to the local copy.
     *
     * @param tempVector caller-allocated temporary storage (not null)
     * @return true if scale factors are exactly equal, otherwise false
     */
    private boolean checkScale(Vector3f tempVector) {
        assert tempVector != null;

        getScaling(nativeId, tempVector);
        boolean result = scale.equals(tempVector);

        return result;
    }

    /**
     * Create a new empty btTriangleIndexVertexArray.
     */
    private void createEmpty() {
        assert nativeId == 0L;

        nativeId = createEmptyTiva();
        assert nativeId != 0L;
        logger.log(Level.FINE, "Created CompoundMesh {0}",
                Long.toHexString(nativeId));
    }
    // *************************************************************************
    // native methods

    native private void addIndexedMesh(long compoundMeshId, long submeshId);

    native private long createEmptyTiva();

    native private void finalizeNative(long compoundMeshId);

    native private void getScaling(long compoundMeshId, Vector3f storeVector);

    native private void setScaling(long compoundMeshId, float xScale,
            float yScale, float zScale);
}
