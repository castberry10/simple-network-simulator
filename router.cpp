#include "router.h"

void Router::receive(Packet *packet){
  send(packet);
}
void Router::send(Packet *packet){
  std::stringstream ss;
  for(std::vector<RoutingEntry>::size_type i = 0; i < routingTable_.size(); i++){
    if(routingTable_[i].destination == packet->destAddress()){
      ss.str("");
      ss.clear();
      ss << "Router #" << id();
      ss << ": forwarding packet (from: ";
      ss << packet->srcAddress().toString();
      ss << ", to: ";
      ss << packet->destAddress().toString();
      ss << ", " << packet->data().size();
      ss << " bytes)";
      log(ss.str());
      routingTable_[i].nextLink->inout(this, packet);
      return;
    }
  }
  ss.str("");
  ss.clear();
  ss << "Router #" << id();
  ss << ": no route for packet (from: ";
  ss << packet->srcAddress().toString();
  ss << ", to: ";
  ss << packet->destAddress().toString();
  ss << ", " << packet->data().size();
  ss << " bytes)" ;
  log(ss.str());

  delete packet;
  return;
}