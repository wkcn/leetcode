// TODO: Rabin-Karp
#include "common.h"

struct DNode {
  DNode *nodes[26];
  bool is_leaf;
  DNode() : is_leaf(false) {
    memset(nodes, 0, sizeof(nodes));
  }
  ~DNode() {
    for (DNode *r : nodes) {
      delete r;
    }
  }
};

class Solution {
public:
  int respace(vector<string>& dictionary, string sentence) {
    DNode *root = BuildDTree(dictionary);
    const int len = sentence.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 0; i < len; ++i) {
      // 计算dp[i + 1]的值
      dp[i + 1] = dp[i] + 1; // 假如当前的字符不能识别
      DNode *r = root;
      // 从后往前检查
      for (int j = i; j >= 0; --j) {
        r = r->nodes[sentence[j] - 'a'];
        if (r == nullptr) break;
        if (r->is_leaf) {
          dp[i + 1] = min(dp[i + 1], dp[j]);
        }
      }
    } 
    delete root;
    return dp.back();
  }
private:
  DNode* BuildDTree(vector<string>& dictionary) {
    DNode *root = new DNode();
    for (string &s : dictionary) {
      DNode *r = root;
      // 生成逆序版的字典树
      for (int i = s.size() - 1; i >= 0; --i) {
        char c = s[i];
        DNode *&t = r->nodes[c - 'a'];
        if (t == nullptr) t = new DNode();
        r = t;
      }
      r->is_leaf = true;
    }
    return root;
  } 
};

int main() {
  vector<string> dictionary;
  INPUT_ARRAY(dictionary);
  string sentence;
  cin >> sentence;
  cout << Solution().respace(dictionary, sentence) << endl;
  return 0;
}
