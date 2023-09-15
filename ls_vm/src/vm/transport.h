#pragma once

#include "queue.h"
#include "mtx.h"
#include "constants.h"



enum TransportStatus{
  T_STATUS_BUFFER,
  T_STATUS_TO_WAY,
  T_STATUS_SUCCESS,
  T_STATUS_ERROR,
};

class Transport: public QueueElement{
public:
  int _ownerId;
  int _targetId;
  int _size;
  TransportStatus _status;
  u8 data[TRANSPORT_DATA_SIZE];
};

class TransportQueue {
private:
  Queue q;
public:
  TransportQueue(){};

public:
  inline void push(Transport* m){ 
    q.push(m);
  }

  inline void pushAll(TransportQueue& gueue){ 
    q.pushAll(gueue.q);
  }

  inline Transport* pop(){
    return (Transport*)(q.pop());
  }

  inline bool isEmpty(){
    return q.isEmpty();
  }

  inline bool isNotEmpty(){
    return q.isNotEmpty();
  }
};


