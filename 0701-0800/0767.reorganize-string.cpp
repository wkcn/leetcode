#include "common.h"

class Solution {
public:
    string reorganizeString(string S) {
        const int len = S.size();
        if (len <= 1) return S;
        const int U = (len + 1) / 2;
        array<int, 26> cnts{0};
        for (char &c : S) {
            ++cnts[c - 'a'];
        }
        int best = 0;
        int best_i;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] > best) {
                best = cnts[i];
                best_i = i;
            }
        }
        if (best > U) return {};
        // 0, 1, 2, 3, 4, 5
        // 0, 3, 1, 4, 2, 5

        // 0, 1, 2, 3, 4
        // 0, 3, 1, 4, 2
        for (int i = 0; i < len; ++i) S[i] = 0;
        int ind = 0;
        int e;
        for (e = 0; e < len; ++e) {
            S[ind] = best_i + 'a';
            ind += 2;
            if (ind >= len) ind = 1;
            if (--cnts[best_i] == 0) {
                break;
            }
        }
        // 将剩下的填充完
        int k = 0;
        for (++e; e < len; ++e) {
            while (cnts[k] == 0) {
              ++k;
            }
            S[ind] = k + 'a';
            --cnts[k];
            ind += 2;
            if (ind >= len) ind = 1;
        }
        return S;
    }
};

int main() {
  string S;
  cin >> S;
  cout << Solution().reorganizeString(S) << endl;
  return 0;
}
