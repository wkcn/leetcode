#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        const int SLEN = s.size();
        const int PLEN = p.size();
        vector<vector<int> > dp(1 + SLEN, vector<int>(1 + PLEN, false));
        dp[0][0] = true;
        for (int i = 1; i < PLEN && p[i] == '*'; i += 2) {
            dp[0][i + 1] = true;
        }
        for (int i = 0; i < SLEN; ++i) {
            for (int j = 0; j < PLEN; ++j) {
                 dp[i+1][j+1] = (s[i] == p[j] || p[j] == '.') ? dp[i][j] : \
                    (j > 0 && p[j] == '*' && (dp[i+1][j-1] || (
                            (s[i] == p[j-1] || p[j-1] == '.') && (
                                dp[i][j-1] || dp[i][j+1]
                            )
                        )
                    ));
            }
        }
        return dp[SLEN][PLEN];
    }
};

int main() {
  string s, p;
  cin >> s >> p;
  cout << Solution().isMatch(s, p) << endl;
  return 0;
}
