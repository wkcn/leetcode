#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
      // 由于被选取的数字只有1到9, 为了得到最大整数, 必须先选大的
      // 完全背包, 可以重复选
      vector<string> dp(target + 1);
      vector<bool> valid(target + 1, false); valid[0] = true;
      for (int i = 9; i >= 1; --i) {
        for (int f = 0; f <= target - cost[i - 1]; ++f) {
          int t = f + cost[i - 1]; 
          if (valid[f]) {
            // 根据数字放置顺序, 同样长度先放的肯定更大
            if (valid[t] && dp[f].size() + 1 < dp[t].size()) continue;
            string new_v = dp[f];
            new_v += (i + '0');
            if (!valid[t] || new_v.size() > dp[t].size() || new_v > dp[t]) {
              dp[t] = new_v;
              valid[t] = true;
            }
          }
        }
      }
      return valid[target] ? dp[target] : "0";
    }
};
#elif SOLUTION == 2

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
      // 注意, 不能全部初始化为0, 因为要恰好.
      vector<int> dp(target + 1, INT32_MIN);
      dp[0] = 0;
      vector<int> moves(target + 1, -1);
      for (int u = 9; u >= 1; --u) {
        for (int i = 0; i <= target - cost[u - 1]; ++i) {
          const int t = i + cost[u - 1];
          int s = dp[i] + 1;
          if (s > dp[t]) {
            dp[t] = s;
          }
        }
      }
      if (dp[target] <= 0) return "0";
      string ans;
      int c = target;
      for (int u = 9; u >= 1; --u) {
        // 注意dp相减时, 不能越界
        while (c >= cost[u-1] && dp[c] == dp[c - cost[u-1]] + 1) {
          ans += '0' + u;
          c -= cost[u - 1];
        }
      }
      return ans;
    }
};

#endif

int main() {
  if (1) {
    vector<int> cost{4,3,2,5,6,7,2,5,5};
    int target = 9;
    cout << Solution().largestNumber(cost, target) << endl;
  }

  {
    vector<int> cost{7,6,5,5,5,6,8,7,8};
    int target = 12;
    cout << Solution().largestNumber(cost, target) << endl;
  }
  return 0;
}
