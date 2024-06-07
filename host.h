#ifndef HOST_H
#define HOST_H

#include "node.h"
#include "address.h"
#include "packet.h"
#include "service.h"
#include <vector>
#include <algorithm>

class Host : public Node {
  friend class ServiceInstaller;

private:
  // 호스트의 주소
  Address address_;
  int default_port_ = 1000;
  std::vector<int> ports_;
  // 설치된 서비스 목록
  std::vector<Service *> services_;

public:
  Address address() { return address_; }
  Host(Address address) : address_(address) {}
  ~Host();
  // 사용 가능한 포트를 반환한다.
  int availablePort();

  // 포트를 사용한다.
  void usePort(int port);
  
  // 포트를 해제한다.
  void releasePort(int port);

  // 호스트와 설치된 서비스를 전부 초기화한다.
  void initialize();

  // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
  void send(Packet *packet);
  void receive(Packet *packet);
};

#endif