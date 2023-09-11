#include <jni.h>
#include <string>

#include <ls_vm.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_ls_porthole_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    LsVm ls;

    std::string hello = "Hello from C++ " + std::to_string(ls.test());

    return env->NewStringUTF(hello.c_str());
}