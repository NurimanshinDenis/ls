
#include "processor.h"
#include <thread>
#include <iostream>

Core* undefanedCore = nullptr;
Core* _cores[CORE_MAX_COUNT] = {0};
int _coreCount = 0;


void runThread(Core* core){
  while(1){
    core->cycle();
  }
}


void Processor::addTransport(int id, Transport* transport){
  transport->_ownerId = id;
  transport->_targetId = -1;
  transport->_status = T_STATUS_BUFFER;
  transport->_size = 0;
  _cores[id]->_in.push(transport);
}

void Processor::addTransports(int id){
  int bufferCount = _coreCount * CORE_MAX_TRANSPORTS + id * CORE_MAX_TRANSPORTS;
  Transport* transportBuffer = new Transport[bufferCount];

  for(int nextId=0; nextId<_coreCount; nextId++){
    for(int t=0; t<CORE_MAX_TRANSPORTS; t++){
      addTransport(nextId, transportBuffer + (--bufferCount));
    }
  }
  while(bufferCount){
    addTransport(id, transportBuffer + (--bufferCount));
  }
}

int Processor::getHardwareConcurrency(Mtx& mtx){
  int WorkerCount = std::thread::hardware_concurrency();
  if(WorkerCount < 2){
      WorkerCount = 2;
  }
  return WorkerCount;
}

int Processor::add(Mtx& mtx, Core* core, bool createTread){
  int id = _coreCount++;
  core->_id = id;
  _cores[id] = core;
  addTransports( id );
  if(createTread){
    std::thread t(runThread, core);
    t.detach();
  }
  return id;
}

int Processor::getCoreCount(Mtx& mtx){
  return _coreCount;
}

void Processor::back(Mtx& mtx, Transport* transport){
  int id = transport->_ownerId;
  bool weekUp = _cores[id]->_in.isEmpty();
  _cores[id]->_in.push(transport);
  mtx.wakeUp(id);
}

void Processor::send(Mtx& mtx, Transport* transport){
  if(transport->_status != T_STATUS_TO_WAY){
    back(mtx, transport);
    return;
  }
  int id = transport->_targetId;
  if(!_cores[id]){
    transport->_status = T_STATUS_ERROR;
    back(mtx, transport);
    return;
  }
  bool weekUp = _cores[id]->_in.isEmpty();
  _cores[id]->_in.push(transport);
  mtx.wakeUp(id);
}

void Processor::sendAll(Mtx& mtx, TransportQueue& sendQ){
  while(sendQ.isNotEmpty()){
    Transport* b = sendQ.pop();
    send(mtx, b);
  }
}






