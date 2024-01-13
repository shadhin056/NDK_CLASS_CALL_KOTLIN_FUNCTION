//
// Created by Moniruzzaman ShadhiN on 13/1/24.
//

#ifndef MY_APPLICATION_MYSINGLETON_H
#define MY_APPLICATION_MYSINGLETON_H

#include <jni.h>
#include <string>

class MySingleton {
private:
    MySingleton() {} // private constructor to enforce Singleton pattern
    static MySingleton* instance;

public:
    static MySingleton* getInstance() {
        if (!instance) {
            instance = new MySingleton();
        }
        return instance;
    }

    std::string callKotlinFunction(JNIEnv* env) {
        // Find the class reference
        jclass kotlinClass = env->FindClass("com/example/myapplication/MyKotlinClass");

        // Check if the class is found
        if (kotlinClass == nullptr) {
            return "Class not found";
        }

        // Create an object of the class
        jobject kotlinObject = env->AllocObject(kotlinClass);

        // Get the method ID for the getHelloWorldString method
        jmethodID method = env->GetMethodID(kotlinClass, "getHelloWorldString", "()Ljava/lang/String;");

        // Check if the method is found
        if (method == nullptr) {
            return "Method not found";
        }

        // Call the method on the object
        jstring result = (jstring)env->CallObjectMethod(kotlinObject, method);

        // Release resources
        const char* str = env->GetStringUTFChars(result, nullptr);
        std::string resultString(str);
        env->ReleaseStringUTFChars(result, str);
        return resultString;
    }
};
MySingleton* MySingleton::instance = nullptr;

#endif //MY_APPLICATION_MYSINGLETON_H
