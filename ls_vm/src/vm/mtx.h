#pragma once

#include <mutex>
#include "types.h"


class Mtx{
private:
  std::unique_lock<std::mutex> lock;
public:
  Mtx();

  void sleep( int index, i64 t );
  void wakeUp( int index );
  void wakeUpAll( int count );
  
};






