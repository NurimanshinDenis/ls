
#include "system/system.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ls_vm>


using namespace std;



int main(){

    System* system = new System();

    LsVm ls;

    ls.test();
    
    while(system->update()){
        this_thread::sleep_for(chrono::milliseconds(16));
    }

    delete system;

    cout << "Goodbay" <<endl;
    
    return 0;
}