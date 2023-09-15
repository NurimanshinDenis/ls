#pragma once


#include "worker.h"
#include "mtx.h"
#include <iostream>


class NodeWorker: public Worker {
protected:

  void onReceive(Transport* in) override;
  void onSend(Transport* out, bool& isRepeat) override ;
  void onSynchronize(Mtx& mtx,i64& sleep) override;
  void onUpdate() override;


public:
  


};





