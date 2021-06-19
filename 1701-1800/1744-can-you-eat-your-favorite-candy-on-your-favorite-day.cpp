#include "common.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
      // queries: q0, q1, q2
      // 在每天吃糖不超过q2的情况下, q1天能吃到类型为q0的糖果
      // 假设糖果编号从1开始数, 第q1天吃到的糖果编号范围是[q1 + 1, q2 * (q1 + 1)]
      const int n = candiesCount.size();
      using LL = long long;
      vector<LL> pre(n); pre[0] = candiesCount[0];
      for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + candiesCount[i];
      vector<bool> ans(queries.size());
      int i = 0;
      for (auto &q : queries) {
        LL left = (LL)q[1] + 1;
        LL right = (LL)q[2] * (q[1] + 1);
        LL t_left = q[0] == 0 ? 1 : pre[q[0] - 1] + 1;
        LL t_right = pre[q[0]];
        ans[i++] = !(left > t_right || right < t_left);
      }
      return ans;
    }
};

int main() {
  // 0, 7, 11, 16, 19, 27
  vector<int> candiesCount{7, 4, 5, 3, 8};
  vector<vector<int>> queries{{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}};
  PRINT_ARRAY(Solution().canEat(candiesCount, queries));
  return 0;
}
