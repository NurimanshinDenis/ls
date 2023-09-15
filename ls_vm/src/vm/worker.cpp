
#include "worker.h"


void Worker::cycleSynchronize(){
  Mtx mtx;
  Processor::sendAll(mtx, _send);
  _receive.pushAll(getIn(mtx));
  i64 sleep = 1000;
  onSynchronize(mtx,sleep);
  if( _receive.isEmpty() ){
    mtx.sleep(getId(),sleep);
  }
}

void Worker::cycleReceive(){
  while(_receive.isNotEmpty()){
    Transport* in = _receive.pop();
    if(in->_status == T_STATUS_BUFFER){
      _buffer.push(in);
      continue;
    }

    onReceive(in);

    if( in->_ownerId == getId() ){
      _buffer.push(in);
      continue;
    }

    if(in->_status == T_STATUS_TO_WAY ){
      in->_status = T_STATUS_ERROR;
    }
    _send.push( in );
  }
}

void Worker::cycleSend(){
  while(1){
    if(!out){
      out = _buffer.pop();
      out->_targetId = -1;
      out->_status = T_STATUS_BUFFER;
      out->_size = 0;
    }
    if(!out){
      break;
    }
    bool isRepeat = false;
    onSend(out,isRepeat);

    if(out->_targetId > -1 && out->_status == T_STATUS_TO_WAY){
      _send.push( out );
      out=nullptr;
    }
    if(!isRepeat){
      break;
    }
  }
}

void Worker::cycle(){
  cycleSynchronize();
  cycleReceive();
  onUpdate();
  cycleSend();
};





