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
  // std::string logstring;
  std::stringstream ss;
  ss << "EchoService: received \"";
  ss << packet->dataString() << "\" from ";
  ss << packet->srcAddress().toString() << ":";
  ss << packet->srcPort() << ", ";
  ss << "send reply with same data";
  log(ss.str());
  send(packet);
}
