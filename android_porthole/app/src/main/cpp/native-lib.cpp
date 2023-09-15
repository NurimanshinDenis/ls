#include <jni.h>
#include <string>

#include <ls_vm.h>

LsVm ls;


extern "C"
JNIEXPORT jstring JNICALL
Java_com_ls_porthole_MainActivity_lsVmUpdateJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++ " + std::to_string(ls.update());

    return env->NewStringUTF(hello.c_str());
}