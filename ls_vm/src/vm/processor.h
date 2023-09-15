#pragma once


#include "mtx.h"
#include "transport.h"


class Core {
private:
  int _id = -1;
  TransportQueue _in;

protected:
  inline TransportQueue& getIn(Mtx& mtx){
    return _in;
  }

public:
  Core(){}
  inline int getId(){
    return _id;
  }
  virtual void cycle() = 0;

  friend class Processor;
};

class Processor{
private:
  static void addTransport(int id, Transport* transport);
  static void addTransports(int id);
  static void back(Mtx& mtx, Transport* transport);
  static void send(Mtx& mtx, Transport* transport);
public:
  static int getHardwareConcurrency(Mtx& mtx);
  static int add(Mtx& mtx, Core* core, bool createTread);
  static int getCoreCount(Mtx& mtx);
  static void sendAll(Mtx& mtx, TransportQueue& sendQ);
};



