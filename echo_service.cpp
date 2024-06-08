#include "echo_service.h"

void EchoService::send(Packet * packet){
  Address preDestAdress = packet->destAddress();
  Address preSrcAdress = packet->srcAddress();
  short preDestPort = packet->destPort();
  short preSrcPort = packet->srcPort();
  std::string preData = packet->dataString(); 

  Packet * newPacket = new Packet(preDestAdress, preSrcAdress, preDestPort, preSrcPort, preData);
  delete packet;

  host_->send(newPacket);
}

void EchoService::receive(Packet * packet){
  std::cout << "EchoService: received \"";
  std::cout << packet->dataString() << "\" from ";
  std::cout << packet->srcAddress().toString() << ":";
  std::cout << packet->srcPort() << ", ";
  std::cout << "send reply with same data";
  std::cout << std::endl;
  send(packet);
}
