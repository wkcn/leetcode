#include "common.h"

class Solution {
  const int MOD = int(1e9) + 7;
public:
    int countPairs(vector<int>& deliciousness) {
      // 1: 0001
      // 3: 0011
      // 7: 0111
      int ans = 0;
      unordered_map<int, int> cnts;
      for (int x : deliciousness) {
        // 注意x == 0的情况
        for (int k = 1 << 21; k >= max(x, 1); k >>= 1) {
          int other = k - x;
          auto p = cnts.find(other);
          if (p != cnts.end())
            ans = (ans + p->second) % MOD;
        }
        ++cnts[x];
      }
      return ans;
    }
};

int main() {
  vector<int> deliciousness{1,3,5,7,9};
  //vector<int> deliciousness{149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
  cout << Solution().countPairs(deliciousness) << endl;
  return 0;
}
