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
  std::string name() override {
    return std::string("AutoRouter");
  }

  // 라우팅 테이블
  std::map<Node*, std::map<Node*, Node*>> routing_table;

public:
  void calculate(const std::vector<Node *> &nodes,
                 const std::vector<Link *> &links) {

    int n = nodes.size();
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n, std::numeric_limits<double>::infinity()));

    for (int k = 0; k < links.size(); k++) {
      Link *l = links[k];
      int a = std::find(nodes.begin(), nodes.end(), l->nodeA()) - nodes.begin();
      int b = std::find(nodes.begin(), nodes.end(), l->nodeB()) - nodes.begin();
      matrix[a][b] = l->delay();
      matrix[b][a] = l->delay(); 
    }

    for (int src = 0; src < n; ++src) {
      std::vector<double> dist(n, std::numeric_limits<double>::infinity());
      std::vector<int> prev(n, -1);
      dist[src] = 0;

      std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;
      pq.push({0, src});

      while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
          if (matrix[u][v] != std::numeric_limits<double>::infinity()) {
            double alt = dist[u] + matrix[u][v];
            if (alt < dist[v]) {
              dist[v] = alt;
              prev[v] = u;
              pq.push({alt, v});
            }
          }
        }
      }

      for (int dest = 0; dest < n; ++dest) {
        if (src != dest) {
          int next_hop = dest;
          while (prev[next_hop] != src && prev[next_hop] != -1) {
            next_hop = prev[next_hop];
          }
          if (prev[next_hop] == src) {
            routing_table[nodes[src]][nodes[dest]] = nodes[next_hop];
          }
        }
      }
    }
  }

  Node* getNextHop(Node* src, Node* dest) {
    if (routing_table.find(src) != routing_table.end() && routing_table[src].find(dest) != routing_table[src].end()) {
      return routing_table[src][dest];
    }
    return nullptr;
  }
};

#endif
