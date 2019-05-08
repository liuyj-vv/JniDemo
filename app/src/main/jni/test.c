#include <com_jnidemo_JniDemo.h>

//返回一个字符串
JNIEXPORT jstring JNICALL Java_com_jnidemo_JniDemo_getString(JNIEnv *env, jclass jobj) {
    return (*env)->NewStringUTF(env,"HelloWorld 我是用jni调用出来的字符串");
}
