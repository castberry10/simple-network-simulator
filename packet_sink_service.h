#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include <string>

class PacketSinkService : public Service {
  friend class PacketSinkServiceInstaller;
private:
  PacketSinkService(Host *host, short port) : Service(host, port) {};
  std::string name() override {
    return std::string("PacketSinkService");
  }
    void send(Packet * packet);
    void receive(Packet * packet); 
};

#endif