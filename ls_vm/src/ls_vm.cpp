#include "ls_vm.h"

#include "vm/processor.h"
#include "vm/worker_node.h"
#include "vm/mtx.h"

NodeWorker* mainWorker = nullptr;

void LsVm::init(){

  if(mainWorker){
    return;
  }
  mainWorker = new NodeWorker();

  {
    Mtx mtx;

    Processor::add(mtx, mainWorker, false);

    int nodeCoreCount = Processor::getHardwareConcurrency(mtx);
    for(int i=0; i< nodeCoreCount; i++){
      Processor::add(mtx, new NodeWorker(), true);
    }
  }
}


i64 LsVm::update(){

  init();
  
  std::cout << std::endl << std::endl;
  mainWorker->cycle();

  return 888;
}