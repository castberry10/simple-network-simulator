#include "router.h"

void Router::receive(Packet *packet){
  send(packet);
}
void Router::send(Packet *packet){
  for(int i = 0; i < routingTable_.size(); i++){
    if(routingTable_[i].destination == packet->destAddress()){
      routingTable_[i].nextLink->inout(this, packet);
    }
  }
}