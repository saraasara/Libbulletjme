/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_joints_SliderJoint */

#ifndef _Included_com_jme3_bullet_joints_SliderJoint
#define _Included_com_jme3_bullet_joints_SliderJoint
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    createJoint
 * Signature: (JJLcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;Lcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;Z)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_SliderJoint_createJoint
  (JNIEnv *, jobject, jlong, jlong, jobject, jobject, jobject, jobject, jboolean);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    createJoint1
 * Signature: (JLcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;Z)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_SliderJoint_createJoint1
  (JNIEnv *, jobject, jlong, jobject, jobject, jboolean);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingDirAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingDirAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingDirLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingDirLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingLimAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingLimAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingLimLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingLimLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingOrthoAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingOrthoAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getDampingOrthoLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getDampingOrthoLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getFrameOffsetA
 * Signature: (JLcom/jme3/math/Transform;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_getFrameOffsetA
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getFrameOffsetB
 * Signature: (JLcom/jme3/math/Transform;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_getFrameOffsetB
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getLowerAngLimit
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getLowerAngLimit
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getLowerLinLimit
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getLowerLinLimit
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getMaxAngMotorForce
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getMaxAngMotorForce
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getMaxLinMotorForce
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getMaxLinMotorForce
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionDirAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionDirAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionDirLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionDirLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionLimAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionLimAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionLimLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionLimLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionOrthoAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionOrthoAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getRestitutionOrthoLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getRestitutionOrthoLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessDirAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessDirAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessDirLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessDirLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessLimAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessLimAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessLimLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessLimLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessOrthoAng
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessOrthoAng
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getSoftnessOrthoLin
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getSoftnessOrthoLin
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getTargetAngMotorVelocity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getTargetAngMotorVelocity
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getTargetLinMotorVelocity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getTargetLinMotorVelocity
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getUpperAngLimit
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getUpperAngLimit
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    getUpperLinLimit
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_SliderJoint_getUpperLinLimit
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    isPoweredAngMotor
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jme3_bullet_joints_SliderJoint_isPoweredAngMotor
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    isPoweredLinMotor
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jme3_bullet_joints_SliderJoint_isPoweredLinMotor
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingDirAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingDirAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingDirLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingDirLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingLimAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingLimAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingLimLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingLimLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingOrthoAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingOrthoAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setDampingOrthoLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setDampingOrthoLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setLowerAngLimit
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setLowerAngLimit
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setLowerLinLimit
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setLowerLinLimit
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setMaxAngMotorForce
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setMaxAngMotorForce
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setMaxLinMotorForce
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setMaxLinMotorForce
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setPoweredAngMotor
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setPoweredAngMotor
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setPoweredLinMotor
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setPoweredLinMotor
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionDirAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionDirAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionDirLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionDirLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionLimAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionLimAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionLimLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionLimLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionOrthoAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionOrthoAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setRestitutionOrthoLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setRestitutionOrthoLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessDirAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessDirAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessDirLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessDirLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessLimAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessLimAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessLimLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessLimLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessOrthoAng
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessOrthoAng
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setSoftnessOrthoLin
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setSoftnessOrthoLin
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setTargetAngMotorVelocity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setTargetAngMotorVelocity
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setTargetLinMotorVelocity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setTargetLinMotorVelocity
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setUpperAngLimit
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setUpperAngLimit
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_joints_SliderJoint
 * Method:    setUpperLinLimit
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SliderJoint_setUpperLinLimit
  (JNIEnv *, jobject, jlong, jfloat);

#ifdef __cplusplus
}
#endif
#endif
