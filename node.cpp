#include "node.h"
#include <iostream>

int Node::nextId_ = 0;

void Node::installLink(Link * link){
    links.push_back(link);   
}


void Node::receive(Packet *packet){
    std::cout << "node: receive" << std::endl;

}
void Node::send(Packet *packet){
    std::cout << "node: send" << std::endl;
    
}
Node::~Node() {}