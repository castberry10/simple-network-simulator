#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "object.h"
#include "packet.h"
#include <vector>

class Link;

class Node : public Object{
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  std::string name() override {
    return std::string("Node");
  }

protected:
  std::vector<Link *> links;
  void installLink(Link * link); 
public:
  Node() : id_(nextId_++) {}
  int id() const { return id_; }
  virtual ~Node();
  virtual void receive(Packet *packet);
  virtual void send(Packet *packet);
};

#endif