// TODO: DP
#include "common.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // (pos, step)
      set<pair<int, int>> se;
      pq.push({stones[0] + 1, 1});
      for (int i = 1; i < int(stones.size()) - 1; ++i) {
        while (!pq.empty() && pq.top().first <= stones[i]) {
          auto p = pq.top(); pq.pop();
          if (se.count(p)) continue;
          se.insert(p);
          auto [pos, step] = p;
          if (pos < stones[i]) continue;
          // pos == stones[i]
          for (int d = -1; d <= 1; ++d) {
            pq.push({pos + step + d, step + d});
          }
        }
      }
      while (!pq.empty()) {
        auto [pos, step] = pq.top(); pq.pop();
        if (pos == stones[stones.size() - 1]) return true;
      }
      return false;
    }
};

int main() {
  {
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  cout << Solution().canCross(stones) << endl;
  }
  if (1) {
  vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
  cout << Solution().canCross(stones) << endl;
  }
  return 0;
}
