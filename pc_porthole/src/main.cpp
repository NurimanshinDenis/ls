
#include "system/system.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ls_vm.h>


using namespace std;


int main(){

    System* system = new System();

    LsVm ls;

    cout << "ls.test(); " << ls.test() << endl;
    
    while(system->update()){
        this_thread::sleep_for(chrono::milliseconds(16));
    }

    delete system;

    cout << "Goodbay" <<endl;
    
    return 0;
}