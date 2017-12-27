#ifndef MAIN_H
#define MAIN_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL encrypt(JNIEnv *env, jobject thiz, jstring plaintext);

JNIEXPORT jstring JNICALL decrypt(JNIEnv *env, jobject thiz, jstring ciphertext);

#ifdef __cplusplus
}
#endif
#endif
