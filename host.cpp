#include "host.h"
#include <iostream>
#include <cstdlib>

Host::~Host() {
  
}

void Host::initialize(){
  ports_.clear();
  for(std::vector<Service*>::size_type i = 0; i < services_.size(); i++){
    if(services_[i]->getPort() == -1){
      int hostport = this->availablePort();
      this->usePort(hostport);
      services_[i]->setPort(hostport);
    }
    // services_[i]->setPort()
    // services_
  }
  return;
  
}

void Host::send(Packet *packet){
  int randlinkindex = rand() % links.size();

  std::cout << "Host #" << id();
  std::cout << ": sending packet (from: ";
  std::cout << packet->srcAddress().toString();
  std::cout << ", to: ";
  std::cout << packet->destAddress().toString();
  std::cout << ", " << packet->data().size();
  std::cout << " bytes)" << std::endl;

  links[randlinkindex]->inout(this, packet);
  return;
}

void Host::receive(Packet * packet){
  
  for(std::vector<Service*>::size_type i = 0; i < services_.size(); i++){
    // std::cout << "services_[i]->getPort()" << services_[i]->getPort() << std::endl;
    // std::cout << "packet->destPort()" << packet->destPort() << std::endl;
    
    if(services_[i]->getPort() == packet->destPort()){
      std::cout << "Host #" << id();
      std::cout << ": received packet, destination port: ";
      std::cout << packet->destPort();
      std::cout << std::endl;
      services_[i]->receive(packet);      
      return;
    }
  }
  std::cout << "Host #" << id();
  std::cout << ": no service for packet (from: ";
  std::cout << packet->srcAddress().toString();
  std::cout << ", to: ";
  std::cout << packet->destAddress().toString();
  std::cout << ", " << packet->data().size();
  std::cout << " bytes)" << std::endl;
}

int Host::availablePort(){
  int port = default_port_;
  while(1){
    if (std::find(ports_.begin(), ports_.end(), port) == ports_.end()){
      return port;
    }else{
      port++;
    }
  }
}

void Host::usePort(int port){
  ports_.push_back(port);
  return;
}

void Host::releasePort(int port){
  ports_.erase(std::remove(ports_.begin(), ports_.end(), port), ports_.end());
  return;
}

