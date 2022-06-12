#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int L = s.size();
        int z = 0;
        for (char c : s) if (c == '0') ++z;
        int w = 0;
        int ans = min(z, L - z);
        for (int i = 0; i < L; ++i) {
            if (s[i] == '0') ++w;
            // zero | one
            // before: w | i + 1 - w
            // after: z - w | L - i - 1 - (z - w)
            int y = (i + 1 - w) + z - w;
            ans = min(y, ans);
        }
        return ans;
    }
};

#elif SOLUTION == 2

class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int dp0 = 0, dp1 = 0;
      for (char c : s) {
        /*
        if (c == '0') {
          // new_dp0 = dp0;
          // new_dp1 = min(dp0, dp1) + 1;
        } else {
          // new_d0 = dp0 + 1;
          // new_dp1 = min(dp0, dp1);
        }
        */
        dp1 = min(dp0, dp1) + (c == '0');
        dp0 = dp0 + (c == '1');
      }
      return min(dp0, dp1);
    }
};

#elif SOLUTION == 3

class Solution {
public:
    int minFlipsMonoIncr(string s) {
      const int L = s.size();
      // 0
      vector<int> ps(L + 1); ps[0] = 0;
      for (int i = 0; i < L; ++i) {
        ps[i + 1] = ps[i] + (s[i] == '0');
      }
      int ans = L;
      for (int i = 0; i <= L; ++i) {
        ans = min(ans, (i - ps[i]) + (ps[L] - ps[i]));
      }
      return ans;
    }
};

#endif

int main() {
  string s = "00110";
  cout << Solution().minFlipsMonoIncr(s) << endl;
  return 0;
}
