#include "host.h"
#include <iostream>
#include <cstdlib>
// #include <ctime>
// class Host : public Node {
//   friend class ServiceInstaller;

// private:
//   // 호스트의 주소
//   Address address_;

//   // 설치된 서비스 목록
//   std::vector<Service *> services_;

// public:
//   Address address() { return address_; }
//   Host(Address address) : address_(address) {}

//   // 호스트와 설치된 서비스를 전부 초기화한다.
//   void initialize();

//   // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
//   void send(Packet *packet);
// };
Host::~Host() {
  // for (std::vector<Service*>::iterator it = this->services_.begin(); it != this->services_.end(); it++) {
    //Service* service = *it; 
    //std::cout << "delete service"  << std::endl;
    //delete service;
  // }
}

void Host::initialize(){
  // services_.clear();
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
  std::cout << " byte)" << std::endl;

  links[randlinkindex]->inout(this, packet);
  return;
}

void Host::receive(Packet * packet){
  std::cout << "Host #" << id();
  std::cout << ": received packet, destination port: ";
  std::cout << packet->destPort();
  std::cout << std::endl;
  for(std::vector<Service*>::size_type i = 0; i < services_.size(); i++){
    if(services_[i]->getPort() == packet->destPort()){
      services_[i]->receive(packet);      
      return;
    }
  }
  std::cout << "Host #" << id();
  std::cout << ": no service for packet (from: ";
  std::cout << packet->srcAddress().toString();
  std::cout << ", to: ";
  std::cout << ", " << packet->data().size();
  std::cout << " byte)" << std::endl;
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

