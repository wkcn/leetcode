#include "common.h"

// 看清变量
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string t;
        for (char c : S) if (c != '-') t += toupper(c);
        int y = t.size() % K;
        if (y == 0) y = K;
        // 用对变量，且不要越界
        string ans = t.substr(0, min(y, (int)t.size()));
        int k = 0;
        for (; y < t.size(); ++y) {
            if (k++ % K == 0) ans += '-';
            ans += t[y];
        }
        return ans;
    }
};


int main() {
  string S; int K;
  // cin >> S >> K;
  S = "2-4A0r7-4k";
  K = 4;
  cout << Solution().licenseKeyFormatting(S, K) << endl;
  return 0;
}
