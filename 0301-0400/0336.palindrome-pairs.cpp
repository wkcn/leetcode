// TODO: O(n)求回文字
// 闭区间解法
// 好好理解不同区间怎么去重
// 好题
#include "common.h"

struct DNode {
  DNode() : flag(-1) {
    memset(next, 0, sizeof(next));
  }
  ~DNode() {
    for (DNode *r: next) delete r;
  }
  DNode *next[26];
  int flag;  // 由于输入保证唯一
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      DNode *root(new DNode);
      vector<vector<int> > out;
      for (int i = 0; i < words.size(); ++i) {
        insert(root, words[i], i);
      }
      // 如何避免重复组合，当两个字符串长度相同时，当前字符串一定在左边，因为它不能处理自己在右边的情况
      for (int i = 0; i < words.size(); ++i) {
        const string &s = words[i];
        const int len = s.size();
        // 包含j = len
        for (int j = 0; j <= len; ++j) {
          // 从整个字符串到空，吃左边
          // (0, len), (1, len), (2, len), ..., (len, len)
          if (IsPalindrome(s, j, len)) {
            // 看清开闭区间
            int id = FindWord(root, s, 0, j);
            if (id != -1 && id != i) {
              // 看清下标
              out.push_back({i, id});
            }
          }
          // 两个字符串不相等时
          if (j < len && IsPalindrome(s, 0, len - j)) {
            int id = FindWord(root, s, len - j, len);
            if (id != -1 && id != i) {
              out.push_back({id, i});
            }
          }
        }
      }
      delete root;
      return out;
    }
    void insert(DNode *root, const string &s, int id) {
      for (const char &c : s) {
        DNode* &r = root->next[c - 'a'];
        if (!r) r = new DNode;
        root = r;
      }
      root->flag = id;
    }
    bool IsPalindrome(const string &s, int start, int end) {
      int right = end - 1;
      while (start < right) {
        if (s[start++] != s[right--]) return false;
      }
      return true;
    }
    int FindWord(DNode *root, const string &s, int start, int end) {
      while (start < end) {
        char c = s[--end];
        root = root->next[c - 'a'];
        if (!root) return -1;
      }
      return root->flag;
    }
};


int main() {
  int n; cin >> n;
  vector<string> words;
  for (int i = 0; i < n; ++i) {
    string word; cin >> word;
    words.push_back(word);
  }
  for (auto &vs : Solution().palindromePairs(words))
    PRINT_ARRAY(vs);
  return 0;
}
