#include "bulk_send_service.h"
// BulkSendService
// 정해진 시간동안, 정해진 딜레이마다 512 바이트의 패킷을 전송하는 서비스.
   
void BulkSendService::send(Packet * packet){
    for(double i = startTime_; i < stopTime_; i += delay_){
        std::stringstream ss;
        for(int j = 0; j < 128; j++){
            ss << "1234";
        }
        Packet *packet = new Packet(host_->address(), destAddress_, port_, destPort_, ss.str());
        host_->send(packet);
    }
}

void BulkSendService::receive(Packet * packet){

}