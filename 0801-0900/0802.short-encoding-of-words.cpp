#include "common.h"

class TrieTree {
public:
    TrieTree() : count(0), subs{nullptr} {

    }
    TrieTree* get(char c) {
      int i = c - 'a';
      if (!subs[i]) {
        subs[i] = new TrieTree();
        ++count;
      }
      return subs[i]; 
    }
    int count;
private:
    array<TrieTree*, 26> subs;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      TrieTree *root = new TrieTree();
      unordered_map<TrieTree*, int> ma;
      for (int si = 0; si < words.size(); ++si) {
        string &s = words[si];
        TrieTree *cur = root;
        for (int i = s.size() - 1; i >= 0; --i) {
          cur = cur->get(s[i]);
        }
        ma[cur] = si; 
      }
      int ans = 0;
      for (auto &[r, i] : ma) {
        if (r->count == 0) {
          // leaf
          ans += words[i].size() + 1;
        }
      }
      return ans;
    }
};

int main() {
  vector<string> words;
  INPUT_ARRAY(words);
  cout << Solution().minimumLengthEncoding(words) << endl;
  return 0;
}
