#include "common.h"

class Solution {
public:
    string minWindow(string s, string t) {
        const int tlen = t.size();
        if (tlen == 0) return {};
        const int slen = s.size();
        if (slen == 0) return {};
        int need = tlen;
        array<int, 256> cnts{0};
        array<bool, 256> used{false};
        for (char &c : t) {
            ++cnts[c];
            used[c] = true;
        }
        int i = 0, j = 0;
        int best = INT32_MAX; // 注意best可能与slen相等
        int best_i = -1;
        while (j < slen) {
            for (;j < slen && need > 0; ++j) {
                char &c = s[j];
                if (used[c]) {
                    if (--cnts[c] >= 0) --need;
                }
            }
            if (need > 0) break;
            for (;i < slen; ++i) {
                char &c = s[i];
                if (used[c]) {
                    if (++cnts[c] > 0) {
                        ++need;
                        ++i; // 要加1
                        break;
                    }
                }
            }
            int cur_len = j - i + 1;
            if (cur_len < best) {
                best = cur_len;
                best_i = i - 1;
            }
        }
        if (best_i == -1) return {}; // 退出大循环后再考虑返回
        return s.substr(best_i, best);
    }
};

int main() {
  string s, t;
  cin >> s >> t;
  cout << Solution().minWindow(s, t) << endl;
  return 0;
}
