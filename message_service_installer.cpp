

#include "message_service_installer.h"

MessageService* MessageServiceInstaller::install(Host* host) {
    // int hostport = host->availablePort();
    // host->usePort(hostport);
    MessageService* messageService=new MessageService(host, -1, destAddress_, destPort_);
    ServiceInstaller::install(host, messageService);
    return messageService;
}