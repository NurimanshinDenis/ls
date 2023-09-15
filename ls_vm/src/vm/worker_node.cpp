#include "worker_node.h"
#include "mtx.h"
#include <iostream>


void NodeWorker::onReceive(Transport* in){
  
  if(in->_ownerId == getId()){
    std::cout << getId() << " NodeWorker.onBack " << in->_ownerId << "->" << in->_targetId << " " << in->_status << std::endl;
  }else{
    std::cout << getId() << " NodeWorker.onReceive " << in->_ownerId << "->" << in->_targetId << " " << in->_status << std::endl;
    in->_status = T_STATUS_SUCCESS;
  }
}
void NodeWorker::onSend(Transport* out, bool& isRepeat){
  static bool isSended = false;
  if(getId() == 0 && !isSended){
    isSended = true;
    out->_targetId = 2;
    out->_status = T_STATUS_TO_WAY;
    std::cout << getId() << " NodeWorker.send " << out->_ownerId << "->" << out->_targetId << std::endl;
  }
};
void NodeWorker::onSynchronize(Mtx& mtx,i64& sleep){
  sleep = 5000;
}
void NodeWorker::onUpdate(){
  std::cout << getId() << " NodeWorker.onUpdate"<< std::endl;
}

