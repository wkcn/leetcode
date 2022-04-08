#include "common.h"

struct pii_hash {
  size_t operator()(const pair<int, int> &p) const {
    return p.first | ((size_t)p.second << 32);
  }
};

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
      unordered_set<pair<int,int>, pii_hash> se;
      for (auto &v : blocked) se.emplace(v[0], v[1]);
      // 两个点都没有被围住，或者围在一个圈内
      return check(se, source, target) && check(se, target, source);
    }
    bool check(const unordered_set<pair<int, int>, pii_hash> &se, const vector<int> &p, const vector<int> &t) {
      unordered_set<pair<int, int>, pii_hash> vis;
      vis.emplace(p[0], p[1]);
      queue<pair<int, int>> q;
      q.emplace(p[0], p[1]);
      int cnt = 0;
      while (!q.empty() && cnt <= se.size()) {
        int s = q.size();
        while (s-- > 0) {
          auto r = q.front(); q.pop();
          if (r.first == t[0] && r.second == t[1]) return true;
          for (int i = 0; i < 4; ++i) {
            unsigned int x = r.first + dirs[i][0];
            unsigned int y = r.second + dirs[i][1];
            if (x < 1e6 && y < 1e6 && se.count({x, y}) == 0 && vis.insert({x, y}).second) {
              q.emplace(x, y);
            }
          } 
        }
        ++cnt;
      }
      return q.size() > 0; 
    }
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main() {
  vector<vector<int>> blocked{{0, 1}, {1, 0}};
  vector<int> source{0, 0};
  vector<int> target{0, 2};
  cout << Solution().isEscapePossible(blocked, source, target) << endl;
  return 0;
}
