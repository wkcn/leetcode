// 把符合条件的利润放在优先队列里，优先队列存储的是可以投资的利润
#include "common.h"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      using pii = pair<int, int>;
      vector<pii> cps;
      for (int i = 0; i < profits.size(); ++i) {
        cps.emplace_back(capital[i], profits[i]);
      }
      sort(cps.begin(), cps.end());
      int cur = 0;
      int ans = 0;
      priority_queue<int> pq;
      while (k > 0) {
        while (cur < cps.size() && w >= cps[cur].first) {
          pq.push(cps[cur].second);
          ++cur;
        }
        if (pq.empty()) break;
        // 选一个最大利润的
        w += pq.top(); pq.pop();
        --k;
      }
      return w;
    }
};

int main() {
  int k = 2, w = 0;
  vector<int> profits{1,2,3}, capital{0,1,1};
  cout << Solution().findMaximizedCapital(k, w, profits, capital) << endl;
  return 0;
}
