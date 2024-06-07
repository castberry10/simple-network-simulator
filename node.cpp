#include "node.h"

int Node::nextId_ = 0;

void Node::installLink(Link * link){
    links.push_back(link);   
}