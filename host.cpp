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

  std::stringstream ss;
  ss << "Host #" << id();
  ss << ": sending packet (from: ";
  ss << packet->srcAddress().toString();
  ss << ", to: ";
  ss << packet->destAddress().toString();
  ss << ", " << packet->data().size();
  ss << " bytes)";
  log(ss.str());
  links[randlinkindex]->inout(this, packet);
  return;
}

void Host::receive(Packet * packet){
  std::stringstream ss;

  for(std::vector<Service*>::size_type i = 0; i < services_.size(); i++){
    // std::cout << "services_[i]->getPort()" << services_[i]->getPort() << std::endl;
    // std::cout << "packet->destPort()" << packet->destPort() << std::endl;
    
    if(services_[i]->getPort() == packet->destPort()){
      // std::stringstream ss;
      ss.str("");
      ss.clear();
      ss << "Host #" << id();
      ss << ": received packet, destination port: ";
      ss << packet->destPort();
      log(ss.str());

      services_[i]->receive(packet);      
      return;
    }
  }
  ss.str("");
  ss.clear();
  ss << "Host #" << id();
  ss << ": no service for packet (from: ";
  ss << packet->srcAddress().toString();
  ss << ", to: ";
  ss << packet->destAddress().toString();
  ss << ", " << packet->data().size();
  ss << " bytes)";
  log(ss.str());
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

