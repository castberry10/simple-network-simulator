#ifndef AUTO_ROUTER_H
#define AUTO_ROUTER_H

#include "host.h"
#include "link.h"
#include "router.h"
#include "service.h"
#include <algorithm>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <vector>

class AutoRouter : public Router {
private:
  std::string name(){
    return std::string("a");
  }
public:
  void calculate(const std::vector<Node *> &nodes,
                 const std::vector<Link *> &links) {
    // 전체 노드와 링크 정보를 통해
    // 모든 호스트로 전달될 수 있는 라우팅 테이블을 구성한다
    // TODO: 데이크스트라 구현 
    // 노드 ㅁ
    // std::vector<std::vector<double
    double matrix[10000][10000];

    for(int i = 0; i < nodes.size(); i++){
      for(int j = 0; j < nodes.size(); j++){
        Node * a = nodes[i];
        Node * b = nodes[j];

        matrix[i][j] = 9999999999;
        for(int k = 0; k<links.size(); k++){
          Link* l = links[k];
          if(l->nodeA() == a && l->nodeB() == b){
            matrix[i][j] = l->delay();
          }
        }
      }


    }
    // 다익스트라를 돌리면서 호스트에 대한 최소경로로 갈 수 있는 다음롭을 기록

    for(int i = 0; i<nodes.size(); i++){
      // Node* node = 
    } 
  }
};

#endif