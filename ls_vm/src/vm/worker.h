#pragma once

#include "processor.h"
#include "mtx.h"


class Worker: public Core {
private:

  TransportQueue _buffer;
  TransportQueue _send;
  TransportQueue _receive;
  Transport* out = nullptr;

  void cycleSynchronize();
  void cycleReceive();
  void cycleSend();

protected:

  virtual void onReceive(Transport* in)=0;
  virtual void onSend(Transport* out, bool& isRepeat){ }
  virtual void onSynchronize(Mtx& mtx,i64& sleep){ }
  virtual void onUpdate(){ }

public:

  void cycle() override;
};





