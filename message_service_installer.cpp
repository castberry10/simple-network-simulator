
// class MessageServiceInstaller : public ServiceInstaller {
// private:
//   // 목적지 주소
//   Address destAddress_;
//   // 목적지 포트
//   short destPort_;

// public:
//   MessageServiceInstaller(const Address &destAddress, short destPort)
//       : destAddress_(destAddress), destPort_(destPort) {}

//   // 호스트에 MessageService를 설치한다
//   MessageService *install(Host *host);
// };


// class MessageService : public Service {
//   friend class MessageServiceInstaller;

// private:
//   // 목적지 주소
//   Address destAddress_;
//   // 목적지 포트
//   short destPort_;
//   MessageService(Host *host, short port, Address destAddress, short destPort)
//       : Service(host, port), destAddress_(destAddress), destPort_(destPort) {}

// public:
//   // 메시지를 전송한다
//   void send(std::string message);
// };

#include "message_service_installer.h"

MessageService* MessageServiceInstaller::install(Host* host) {

}