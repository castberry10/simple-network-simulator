#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"
#include "packet.h"

class Host;
class Packet;

class Service {
  friend class ServiceInstaller;

protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}
public:
  short getPort(){return port_;}
  void send(std::string message){}
  void receive(Packet * packet){}
};

#endif