#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"
#include "packet.h"
#include "object.h"

class Host;
class Packet;

class Service: public Object{
  friend class ServiceInstaller;
private:
  std::string name(){
    return std::string("Service");
  }
protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}
public:
  void setPort(short newport){
    port_ = newport;
  }
  short getPort(){return port_;}
  void send(std::string message){}
  virtual void receive(Packet * packet)=0;
  // virtual void serviceInitialize(){}
};


#endif