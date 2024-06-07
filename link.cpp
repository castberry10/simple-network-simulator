#include "link.h"
#include <iostream>

void Link::inout(Node* reqNode, Packet* packet){
  std::cout << "Link: forwarding packet from node #";
  std::cout << packet->srcAddress().toString();
  std::cout << ", to node #";
  std::cout << packet->destAddress().toString();
  std::cout << std::endl;
  other(reqNode)->receive(packet);
}