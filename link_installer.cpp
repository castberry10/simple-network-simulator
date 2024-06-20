// #ifndef LINK_INSTALLER_H
// #define LINK_INSTALLER_H

// #include "link.h"
// #include "service.h"

// class LinkInstaller {
// public:
//   // 노드 a, b 사이에 링크를 설치하고 반환한다.
//   Link *install(Node *a, Node *b);
// };

// #endif

#include "link_installer.h"

Link * LinkInstaller::install(Node *a, Node *b, double delay){
    Link * templink = new Link(a, b, delay);
    a->installLink(templink);
    b->installLink(templink);
    return templink;
}