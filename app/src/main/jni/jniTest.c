#include <com_jnidemo_JniDemo.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <android/log.h>

#ifndef LOG_TAG
#define LOG_TAG "CCCCccc"
#endif

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


void executeCMD(const char *cmd, char *result)
{
    char buf_ps[1024];
    char ps[1024]={0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
            strcat(result, buf_ps);
            if(strlen(result)>1024)
                break;
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
    }
}


int sys(const char * cmdstring)
{
    pid_t pid;
    int status;

    if(cmdstring == NULL){
        return (1);
    }

    if((pid = fork())<0){
        status = -1;
    }
    else if(pid == 0){
        LOGD("%s", cmdstring);
        execl("/system/bin/sh", "sh", "-c", cmdstring, (char *)0);
    }
    else{
        while(waitpid(pid, &status, 0) < 0){
            break;
        }
    }
    return status;
}

char* jstringToChar(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(jstr, mid, strencode);
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}

//返回一个字符串
JNIEXPORT jstring JNICALL Java_com_jnidemo_JniDemo_getString(JNIEnv *env, jclass jobj) {
    return (*env)->NewStringUTF(env,"HelloWorld 我是用jni调用出来的字符串");
}
JNIEXPORT jboolean JNICALL Java_com_jnidemo_JniDemo_setString(JNIEnv *env, jclass jobj, jstring jstring1){
    const char *str = (*env)->GetStringUTFChars(env, jstring1, 0);
    LOGD("%s", str);
    return 1;
}
JNIEXPORT jboolean JNICALL Java_com_jnidemo_JniDemo_setString1(JNIEnv *env, jclass jobj, jstring jstring1) {
    const char *str = (*env)->GetStringUTFChars(env, jstring1, 0);
    char buf[2048]={0};
    LOGD("%s", str);
    executeCMD(str, buf);
    LOGD("buf: %s", buf);
    return 1;
}
