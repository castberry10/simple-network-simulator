#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;
};

class Router : public Node {
private:
std::string name() override {
  return std::string("Router");
}
protected:
  std::vector<RoutingEntry> routingTable_;

public:
  void receive(Packet *packet);
  void send(Packet *packet);
  
};

#endif