#include "router.h"

void Router::receive(Packet *packet){
  send(packet);
}
void Router::send(Packet *packet){
  for(std::vector<RoutingEntry>::size_type i = 0; i < routingTable_.size(); i++){
    if(routingTable_[i].destination == packet->destAddress()){
      std::cout << "Router #" << id();
      std::cout << ": forwarding packet (from: ";
      std::cout << packet->srcAddress().toString();
      std::cout << ", to: ";
      std::cout << packet->destAddress().toString();
      std::cout << ", " << packet->data().size();
      std::cout << " byte)" << std::endl;
      routingTable_[i].nextLink->inout(this, packet);
      return;
    }
  }
  std::cout << "Router #" << id();
  std::cout << ": no route for packet (from: ";
  std::cout << packet->srcAddress().toString();
  std::cout << ", to: ";
  std::cout << ", " << packet->data().size();
  std::cout << " byte)" << std::endl;
  delete packet;
  return;
}