#include "common.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 用DP的方式, a[c]记录的是以字母c为结尾的子串的最长长度
        // 最终答案为以所有字母为结尾的子串的最长长度的和
        char last_c = 0;
        int last_v = 0;
        array<int, 26> dp{0}; // 需要记录, 因为同一个字母可能出现在不同的位置
        for (char c : p) {
            if ((last_c == 'z' && c == 'a') || last_c + 1 == c) {
                // 能和前面的接起来
                ++last_v;
            } else {
                last_v = 1;
            }
            // 这里取最值
            dp[c - 'a'] = max(dp[c - 'a'], last_v);
            last_c = c;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
  string p; cin >> p;
  cout << Solution().findSubstringInWraproundString(p) << endl;
  return 0;
}
