#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
      vector<vector<bool> > T(s.size()+1, vector<bool>(p.size()+1, false));
      T[0][0] = true;
      for (int j = 1; j < p.size(); j += 2) {
        // i = -1
        if (p[j] == '*') {
          T[0][j + 1] = true;
        } else break;
      }
      for (int i = 0; i < s.size(); ++i) {
        for (int j = 0;j < p.size(); ++j) {
          T[i + 1][j + 1] = (T[i][j] && (p[j] == '.' || p[j] == s[i])) ||\
                            (p[j] == '*' && (
                                             T[i+1][j-1] ||\
                                             ((T[i][j-1] || T[i][j+1]) && (p[j-1] == '.' || p[j-1] == s[i]))
                                            ));
        }
      }
      /*
      for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= p.size(); ++j) {
          cout << T[i][j] << "\t";
        }
        cout << endl;
      }
      */
      return T[s.size()][p.size()];
    }
};

int main() {
  string S, P;
  cin >> S >> P;
  cout << Solution().isMatch(S, P) << endl;
  return 0;
}
