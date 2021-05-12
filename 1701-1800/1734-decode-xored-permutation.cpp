#include "common.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
      // n是奇数, 所以encoded的长度是偶数
      const int n = encoded.size() + 1;
      int x1n = 0;
      for (int i = 1; i <= n; ++i) x1n ^= i;
      int v = 0;
      for (int i = 0; i < encoded.size(); i += 2) v ^= encoded[i];
      int last = x1n ^ v;
      vector<int> ans(n);
      ans[n - 1] = last;
      for (int i = n - 2; i >= 0; --i) {
        ans[i] = ans[i + 1] ^ encoded[i];
      }
      return ans;
    }
};

int main() {
  {
    vector<int> encoded{3, 1};
    PRINT_ARRAY(Solution().decode(encoded));
  }
  {
    vector<int> encoded{6, 5, 4, 6};
    PRINT_ARRAY(Solution().decode(encoded));
  }
  return 0;
}
