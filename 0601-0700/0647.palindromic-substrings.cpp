// TODO: 其他两种解法
// Manacher方法
#include "common.h"

class Solution {
public:
    int countSubstrings(string s) {
        // 枚举回文字的中心
        const int len = s.size();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            // s[i]作为奇数长度回文串的中心, 或者偶数长度回文串中心靠左侧的字母
            // 不包括自己, 左边和右边的距离
            const int plen = min(i, len - i - 1);
            int p;
            // 奇数串
            for (p = 1; p <= plen &&
                s[i - p] == s[i + p]; ++p);
            ans += p;
            for (p = 0; p <= plen &&
                s[i - p] == s[i + p + 1]; ++p);
            ans += p;
        }
        return ans;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().countSubstrings(s) << endl;
  return 0;
}
