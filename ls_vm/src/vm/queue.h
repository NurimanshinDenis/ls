#pragma once

#include "types.h"

class QueueElement{
private:
  QueueElement* _next = nullptr;

public:
  QueueElement(QueueElement&) = delete;
  QueueElement(QueueElement&&) = delete;
  QueueElement& operator=(QueueElement&) = delete;
  QueueElement&& operator=(QueueElement&&) = delete;

  QueueElement(){}

  friend class Queue;
};


class Queue{
private:
  QueueElement* _first = nullptr;
  QueueElement* _last = nullptr;
  u64 count = 0;

public:
  Queue(Queue&) = delete;
  Queue(Queue&&) = delete;
  Queue& operator=(Queue&) = delete;
  Queue&& operator=(Queue&&) = delete;

public:
  Queue(){}
  inline void push(QueueElement* element){
    if(!_first){
      _first = element;
      _last = element;
    }else{
      _last->_next = element;
      _last = element;
    }
    count++;
  }

  void pushAll(Queue& gueue){
    if(!gueue._first){
      return;
    }
    if(!_first){
      _first = gueue._first;
    }else{
      _last->_next = gueue._first;
    }
    _last = gueue._last;
    count += gueue.count;

    gueue._first = nullptr;
    gueue._last = nullptr;
    gueue.count = 0;
  }

  QueueElement* pop(){
    if(!_first){
      return nullptr;
    }
    QueueElement* element = _first;
    _first = _first->_next;
    if(!_first){
      _last = nullptr;
    }
    element->_next = nullptr;
    count--;
    return element;
  }

  inline bool isEmpty(){return !count;}
  inline bool isNotEmpty(){return !!count;}
};


