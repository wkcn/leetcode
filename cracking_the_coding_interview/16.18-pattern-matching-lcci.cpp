#include "common.h"

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        // la * na + lb * nb = value.size()
        const int plen = pattern.size();
        const int vlen = value.size();
        int na = 0; for (char &c : pattern) if (c == 'a') ++na;
        const int nb = plen - na;
        // 注意为0的情况
        if (vlen == 0) return (na == 0 || nb == 0);
        // la = (plen - lb * nb) / na, [0, plen / na)
        int max_la = na > 0 ? vlen / na : 0;
        for (int la = 0; la <= max_la; ++la) {
            const int rest = vlen - na * la;
            // 注意nb 可能为0
            if (nb > 0 && rest % nb != 0) continue;
            const int lb = nb > 0 ? rest / nb : 0;
            string sa; string sb;
            bool first_a = true, first_b = true;
            int vi = 0;
            bool fail = false;
            for (char &p : pattern) {
                if (p == 'a') {
                    if (vi + la > vlen) {
                        fail = true; break;
                    }
                    if (first_a) {
                        first_a = false;
                        sa = value.substr(vi, la);
                    } else {
                        if (value.substr(vi, la) != sa) {
                            fail = true; break;
                        }
                    }
                    vi += la;
                } else {
                    if (vi + lb > vlen) {
                        fail = true; break;
                    }
                    if (first_b) {
                        first_b = false;
                        sb = value.substr(vi, lb);
                    } else {
                        if (value.substr(vi, lb) != sb) {
                            fail = true; break;
                        }
                    }
                    vi += lb;           
                }
            }
            if (!fail && vi == vlen && sa != sb) return true;
        }
        return false;
    }
};

int main() {
  string pattern, value;
  cin >> pattern >> value;
  cout << Solution().patternMatching(pattern, value) << endl;
  return 0;
}
