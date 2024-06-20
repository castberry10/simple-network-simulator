#ifndef BULK_SEND_SERVICE_H
#define BULK_SEND_SERVICE_H

#include "host.h"
#include "service.h"
#include "simulator.h"

#define PACKET_SIZE 512

class BulkSendService : public Service {
  friend class BulkSendServiceInstaller;

private:
  Address destAddress_;
  short destPort_;
  double delay_;
  double startTime_;
  double stopTime_;

BulkSendService(Host *host, Address destAddress, short destPort,
                                 double delay, double startTime, double stopTime) :
    Service(host, -1), destAddress_(destAddress), destPort_(destPort), delay_(delay), startTime_(startTime), stopTime_(stopTime) {}
  
std::string name() override  {
  return std::string("BulkSendService");
}
    void send(Packet * packet);
    void receive(Packet * packet);
};

#endif