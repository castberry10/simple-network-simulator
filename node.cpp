#include "node.h"
#include <iostream>

int Node::nextId_ = 0;

void Node::installLink(Link * link){
    links.push_back(link);   
}


void Node::receive(Packet *packet){
    std::stringstream ss;
    ss << "node: receive";
    log(ss.str());
}
void Node::send(Packet *packet){
    std::stringstream ss;
    ss << "node: send";
    log(ss.str());
}
Node::~Node() {}