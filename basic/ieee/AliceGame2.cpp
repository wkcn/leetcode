/*
 * 分治算法
 * 注意避免潜在的O(n^2)
 * 选根节点其实不是很重要
 * 注意选择计数
 */
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <iostream>
#include <tuple>
using namespace std;

bool vis[20010];

vector<pair<int, int> > edges[20010]; // id, len
int rtn_value[20010][4];



int gcd(int a, int b) {
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int res;
int n;

void go(int pid) {
  // find less branches
  /*
  int best_id = pid;
  int min_edge = edges[pid].size();
  queue<pair<int, int> > q;
  q.push({pid, -1});
  while (!q.empty()) {
    pair<int, int> tp = q.front(); q.pop();
    int t = tp.first;
    int parent = tp.second;
    if (edges[t].size() < min_edge) {
      min_edge = edges[t].size();
      best_id = t;
    }
    for (pair<int, int> &p : edges[t]) {
      int e = p.first;
      if (!vis[e] && e != parent) {
        q.push({e, t});
      }
    }
  }
  int pid_bak = pid;
  pid = best_id;
  */
  vector<int> eid;
  for (pair<int, int> & p : edges[pid]) {
    int cid = p.first;
    if (vis[cid]) continue;
    eid.push_back(cid);
    vis[cid] = true;
    go(cid);
    int *rj = rtn_value[cid];
    int rj_cp[4];
    memcpy(rj_cp, rj, sizeof(rj_cp));
    for (int i = 0; i < 4; ++i) {
      rj[i] = rj_cp[(i + 4 - (p.second % 4)) % 4];
    }
  }
  int *co = rtn_value[pid];
  memset(co, 0, sizeof(int)*4);
  for (int i : eid) {
    for (int k = 0; k < 4; ++k) {
      co[k] += rtn_value[i][k];
    }
  }
  int rj[4]; 
  res += co[0] * 2;
  for (int i : eid) {
    int *ri = rtn_value[i];
    for (int k = 0; k < 4; ++k) {
      rj[k] = co[k] - ri[k];
    }
    res += (ri[0] * rj[0] + ri[1] * rj[3] + ri[3] * rj[1] + ri[2] * rj[2]);
  }
  /*
  for (int i = 0; i < eid.size(); ++i) {
    int *ri = rtn_value[eid[i]];
    res += ri[0] * 2;
    for (int k = 0; k < 4; ++k) {
      co[k] += ri[k];
    }
    for (int j = i+1; j < eid.size(); ++j) {
      int *rj = rtn_value[eid[j]];
      res += (ri[0] * rj[0] + ri[1] * rj[3] + ri[3] * rj[1] + ri[2] * rj[2]) * 2;
    }
  }
  */
  co[0]++;
}

int main() {
  while (scanf("%d", &n) && n) {
    memset(vis, 0, sizeof(bool) * (n+1));
    for (int i = 1; i <= n; ++i) {
      if (!edges[i].empty())
        edges[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b, len;
      scanf("%d %d %d", &a, &b, &len);
      edges[a].push_back({b, len});
      edges[b].push_back({a, len});
    }
    res = 0;

    int root = 1;
    /*
    int max_edge = edges[root].size();
    for (int i = 2; i <= n; ++i) {
      if (edges[i].size() > max_edge) {
        max_edge = edges[i].size();
        root = i;
      }
    }
    */
    vis[root] = true;
    go(root);

    int head = res + n;
    int tail = n * n;
    int g = gcd(head, tail);

    printf("%d/%d\n", head / g, tail / g);
  }
  return 0;
}
