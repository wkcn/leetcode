#include "common.h"

class Solution {
  public:
    string removeDuplicateLetters(string s) {
      // xzaxz
      // 当遍历到第二个x时，还不知道x是否能去除，得到xzax
      // 遍历到第二个z时，去除第一个z, xaxz, 然后发现x也能去除，axz
      array<int, 26> cnts{0};
      // cnts是剩下的字母数量
      for (char c : s) ++cnts[c - 'a'];
      array<bool, 26> vis{0};
      string ans;
      for (char c : s) {
        if (!vis[c - 'a']) {
          while (!ans.empty() && ans.back() > c && cnts[ans.back() - 'a'] > 0) {
            // 肯定不在栈里了
            // 这里不用改cnts
            // 注意下面两句的顺序！！！
            vis[ans.back() - 'a'] = false;
            ans.pop_back();
          }
          ans += c;
          vis[c - 'a'] = true;
        }
        // 更新cnts
        --cnts[c - 'a'];
      }
      return ans;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().removeDuplicateLetters(s) << endl;
  return 0;
}
