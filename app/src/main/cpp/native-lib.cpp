#include <jni.h>
#include <string>
#include "MySingleton.h"

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_myapplication_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MyNDKClass_callKotlinFunction(JNIEnv* env, jobject /* this */) {
    MySingleton* singleton = MySingleton::getInstance();
    std::string result = singleton->callKotlinFunction(env);
    return env->NewStringUTF(result.c_str());
}
