/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_collision_shapes_CollisionShape */

#ifndef _Included_com_jme3_bullet_collision_shapes_CollisionShape
#define _Included_com_jme3_bullet_collision_shapes_CollisionShape
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_collision_shapes_CollisionShape
 * Method:    finalizeNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_collision_shapes_CollisionShape_finalizeNative
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_collision_shapes_CollisionShape
 * Method:    getAabb
 * Signature: (JLcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;Lcom/jme3/math/Vector3f;Lcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_collision_shapes_CollisionShape_getAabb
  (JNIEnv *, jobject, jlong, jobject, jobject, jobject, jobject);

/*
 * Class:     com_jme3_bullet_collision_shapes_CollisionShape
 * Method:    isConcave
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jme3_bullet_collision_shapes_CollisionShape_isConcave
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_collision_shapes_CollisionShape
 * Method:    setLocalScaling
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_collision_shapes_CollisionShape_setLocalScaling__JLcom_jme3_math_Vector3f_2
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_jme3_bullet_collision_shapes_CollisionShape
 * Method:    setMargin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_collision_shapes_CollisionShape_setMargin
  (JNIEnv *, jobject, jlong, jfloat);

#ifdef __cplusplus
}
#endif
#endif
