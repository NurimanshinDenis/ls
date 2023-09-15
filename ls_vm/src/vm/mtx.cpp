
#include "mtx.h"
#include "constants.h"
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std::chrono_literals;


std::mutex mtx;
std::condition_variable corecv[CORE_MAX_COUNT];


Mtx::Mtx():lock(mtx){}

//core
void Mtx::sleep(int index, i64 t ){
  if(t<1){
    return;
  }
  corecv[index].wait_for(lock, t * 1ms);
}

void Mtx::wakeUp(int index ){
  corecv[index].notify_one();
}

void Mtx::wakeUpAll( int count ){
  for(int i=0; i< count; i++){
    corecv[i].notify_one();
  }
}



