#include <string.h>
#include "main.h"
#include "xxtea.h"
#include "base64.h"

/**
 * key for XXTEA
 *
 * modify it before you want to use it.
 */
const char *key = "1234567890";


jstring CStr2Jstring( JNIEnv* env, const char* pat)
{
    jclass strClass = (*env)->FindClass(env,"Ljava/lang/String;");
    jmethodID ctorID = (*env)->GetMethodID(env,strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (*env)->NewByteArray(env,(jsize)strlen(pat));
    (*env)->SetByteArrayRegion(env,bytes, 0, (jsize)strlen(pat), (jbyte*)pat);
    jstring encoding = (*env)->NewStringUTF(env,"UTF-8");
    return (jstring)(*env)->NewObject(strClass, ctorID, bytes, encoding);
}

char * Jstring2CStr( JNIEnv * env, jstring jstr )
{
    char * rtn = NULL;
    jclass clsstring = (*env)->FindClass(env,"java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"UTF-8");
    jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(jstr,mid,strencode);
    jsize alen = (*env)->GetArrayLength(env,barr);
    jbyte * ba = (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
    if(alen > 0)
    {
        rtn = (char*)malloc(alen+1); //new char[alen+1];
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env,barr,ba,0);

    return rtn;
}


JNIEXPORT jstring JNICALL encrypt(JNIEnv *env, jobject thiz, jstring plaintext){
    const char *text = Jstring2CStr(env,plaintext);
    size_t len;
    unsigned char *encrypt_data = xxtea_encrypt(text, strlen(text), key, &len);
    char *base64_data = base64_encode(encrypt_data, len);
    return CStr2Jstring(env,base64_data);
};


JNIEXPORT jstring JNICALL decrypt(JNIEnv *env, jobject thiz, jstring ciphertext){
    const char *text = Jstring2CStr(env,ciphertext);
    size_t len;
    unsigned char *base64_data = base64_decode(text, &len);

    char *decrypt_data = xxtea_decrypt(base64_data, len, key, &len);

    return CStr2Jstring(env,decrypt_data);
};
