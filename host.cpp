#include "host.h"
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

void Host::initialize(){
  // this->address_ = id();
  services_.clear();
  return;
}

void Host::send(Packet *packet){
  return;
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
