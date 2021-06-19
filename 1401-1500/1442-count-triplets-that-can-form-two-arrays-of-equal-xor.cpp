#include "common.h"
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        vector<int> pre(n + 1);
        pre[0] = 0;
        for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] ^ arr[i];
        // if a == b => a ^ b = 0
        // a = pre[j] ^ pre[i]
        // b = pre[k + 1] ^ pre[j]
        // pre[i] ^ pre[k + 1] = 0
#define SOLUTION 2

#if SOLUTION == 1
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (pre[i] == pre[k + 1]) {
                    ans += k - i;
                }
            }
        }
        return ans;
#elif SOLUTION == 2
        unordered_map<int, pair<int, int>> ma;  // 异或值, pair对应: (i求和, i次数)
        ma[pre[0]] = {0, 1};
        int ans = 0;
        for (int k = 1; k < n; ++k) {
          // 注意, 一个是下标k + 1, 一个是下标k
          auto &p = ma[pre[k + 1]];
          ans += p.second * k - p.first; 
          auto &q = ma[pre[k]];
          q.first += k;
          ++q.second;
        }
        return ans;
#endif
    }
};

int main() {
  vector<int> arr{2, 3, 1, 6, 7};
  cout << Solution().countTriplets(arr) << endl;
  return 0;
}
