#include "common.h"

struct DNode {
  DNode *nodes[256];
  bool is_word;
  DNode() {
    memset(nodes, 0, sizeof(nodes));
    is_word = false;
  }
  ~DNode() {
    for (DNode *r : nodes)
      delete r;
  }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      DNode root;
      for (string &x : wordDict) {
        DNode *p = &root;
        for (char c : x) {
          DNode *&r = p->nodes[c];
          if (!r) r = new DNode();
          p = r;
        }
        p->is_word = true;
      }
      vector<bool> valid(s.size() + 1, false);
      valid[0] = true;
      for (int i = 0; i < s.size(); ++i) {
        if (!valid[i]) continue;
        DNode *p = &root;
        for (int j = i; j < s.size(); ++j) {
          p = p->nodes[s[j]];
          if (!p) break;
          if (p->is_word) valid[j + 1] = true;
        }
      }
      return valid.back();
    }
};

int main() {
  string s = "leetcode";
  vector<string> wordDict{"leet", "code"};
  cout << Solution().wordBreak(s, wordDict) << endl;
  return 0;
}
