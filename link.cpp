#include "link.h"
#include "node.h"
#include <iostream>

void Link::inout(Node* reqNode, Packet* packet){
  std::cout << "Link: forwarding packet from node #";
  std::cout << reqNode->id();
  std::cout << ", to node #";
  std::cout << other(reqNode)->id();
  std::cout << std::endl;
  other(reqNode)->receive(packet);
}