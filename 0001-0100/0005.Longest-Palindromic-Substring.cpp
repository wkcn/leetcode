// TODO: DP
// https://blog.csdn.net/MapleJam/article/details/52791033
#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
      int len = s.size();
      string S(len * 2 + 3, '#');
      S[0] = '^';
      S[S.size() - 1] = '$';
      vector<int> p(S.size(), 0);
      for (int i = 0; i < len; ++i) {
        S[i * 2 + 2] = s[i];
      }
      int cnt = 0;
      int C = 0, R = 0;
      for (int i = 2; i < S.size() - 2; ++i) {

        int mirror_i = 2 * C - i;
        // abacaba
        if (mirror_i >= 0){
          p[i] = min(p[mirror_i], R - i);
        }

        while(S[i - p[i] - 1] == S[i + p[i] + 1]) {
          ++p[i];
          ++cnt;
        }
        if (i + p[i] > R) {
          C = i;
          R = i + p[i];
        }
      }
      // cout << "CNT:" << cnt << endl;

      int id = 0;
      int maxLen = p[id];
      for (int i = 1;i < p.size();++i){
        if (p[i] > maxLen){
          maxLen = p[i];
          id = i;
        }
      }
      // ^#a#b#a#$
      // ^#b#a#a#b#$

      return s.substr((id - maxLen) / 2,maxLen);
    }
};

int main() {
  {
    string s = "babad";
    Solution so;
    cout << so.longestPalindrome(s) << endl;
  }
  {
    string s(10000, 'a'); 
    Solution so;
    cout << so.longestPalindrome(s).size() << endl;
  }
  return 0;
}
