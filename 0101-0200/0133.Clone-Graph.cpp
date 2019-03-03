#include "common.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
      map<Node*, Node*> old2new;
      queue<pair<Node*, Node*> > qu;
      Node* new_node = new Node();
      Node* nei_node;
      new_node->val = node->val;
      old2new[node] = new_node;
      qu.push({node, new_node});
      while (!qu.empty()) {
        auto p = qu.front(); qu.pop();
        Node *r = p.first, *new_r = p.second;
        for (Node* y : r->neighbors) {
          auto it = old2new.find(y);
          if (it == old2new.end()) {
            nei_node = new Node();
            nei_node->val = y->val; 
            old2new[y] = nei_node;
            qu.push({y, nei_node});
          } else
            nei_node = it->second;

          new_r->neighbors.push_back(nei_node);
        }
      }
      return new_node;
    }
};

void PrintGraphNeighbors(Node* a) {
  set<Node*> vis;
  queue<Node*> qu;
  qu.push(a);
  vis.insert(a);
  while (!qu.empty()) {
    Node* r = qu.front(); qu.pop();
    cout << r->val << ": ";
    bool first = true;
    for (Node* neighbor : r->neighbors) {
      if (!first) cout << ", ";
      else first = false; 
      if (!vis.count(neighbor)) {
        vis.insert(neighbor);
        qu.push(neighbor);
      }
      cout << neighbor->val;
    }
    cout << endl;
  }
}

int main() {
  // start from 1
  // number of nodes
  int n;
  cin >> n;
  // number of edges
  int e;
  cin >> e;
  vector<Node> nodes(n + 1);
  for (int i = 1; i <= n; ++i) { 
    nodes[i].val = i;
  }
  for (int i = 0;i < e;++i) {
    int a, b;
    cin >> a >> b;
    nodes[a].neighbors.push_back(&nodes[b]);
    nodes[b].neighbors.push_back(&nodes[a]);
  }
  PrintGraphNeighbors(&nodes[1]);
  Solution so;
  cout << "===========" << endl;
  Node* new_graph = so.cloneGraph(&nodes[1]);
  PrintGraphNeighbors(new_graph);
  return 0;
}
