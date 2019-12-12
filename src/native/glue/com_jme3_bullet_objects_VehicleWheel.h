/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_objects_VehicleWheel */

#ifndef _Included_com_jme3_bullet_objects_VehicleWheel
#define _Included_com_jme3_bullet_objects_VehicleWheel
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    applyInfo
 * Signature: (JIFFFFFFFFZF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_VehicleWheel_applyInfo
  (JNIEnv *, jobject, jlong, jint, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat, jboolean, jfloat);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getCollisionLocation
 * Signature: (JILcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getCollisionLocation
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getCollisionNormal
 * Signature: (JILcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getCollisionNormal
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getDeltaRotation
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getDeltaRotation
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getSkidInfo
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getSkidInfo
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getWheelLocation
 * Signature: (JILcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getWheelLocation
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     com_jme3_bullet_objects_VehicleWheel
 * Method:    getWheelRotation
 * Signature: (JILcom/jme3/math/Matrix3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_VehicleWheel_getWheelRotation
  (JNIEnv *, jobject, jlong, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
