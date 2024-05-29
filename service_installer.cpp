#include "service_installer.h"

// 서비스를 설치하는 역할
void ServiceInstaller::install(Host *host, Service *service){
  service->host_ = host;
  // 서비스 포트 설정도 해야함
  host->services_.push_back(service);
}
