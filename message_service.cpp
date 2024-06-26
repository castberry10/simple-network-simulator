
// // send 함수를 호출하여 메시지를 전송할 수 있는 서비스
// class MessageService : public Service {
//   friend class MessageServiceInstaller;

// private:
//   // 목적지 주소
//   Address destAddress_;
//   // 목적지 포트
//   short destPort_;
//   MessageService(Host *host, short port, Address destAddress, short destPort)
//       : Service(host, port), destAddress_(destAddress), destPort_(destPort) {}

// #endif
#include "message_service.h"
void MessageService::send(std::string message){
    Packet * newPacket = new Packet(host_->address(),destAddress_, port_,destPort_,message);
    host_->send(newPacket);
}
void MessageService::receive(Packet * packet){
    // Object::Log();
    // log(std::string("aa"));
    std::stringstream ss;
    ss << "MessageService: received \"";
    ss << (packet->dataString()) << "\" from ";
    ss << packet->srcAddress().toString() << ":";
    ss << packet->srcPort();
    log(ss.str());
    delete packet;
}