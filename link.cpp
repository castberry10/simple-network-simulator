#include "link.h"
#include "node.h"
#include <iostream>

void Link::inout(Node* reqNode, Packet* packet){
  std::stringstream ss;
  ss << "Link: forwarding packet from node #";
  ss << reqNode->id();
  ss << ", to node #";
  ss << other(reqNode)->id();
  log(ss.str());
  other(reqNode)->receive(packet);
}