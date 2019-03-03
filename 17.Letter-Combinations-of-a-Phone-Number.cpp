#include "common.h"

const int lsize[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
const char lstr[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

class Solution {
public:
  Solution() {
    for (int i = 2; i <= 9; ++i) {
      for (int j = 0; j < lsize[i]; ++j) {
        char c = lstr[i][j];
        next[c] = j < lsize[i] - 1 ? lstr[i][j + 1] : -1;
        group[c] = i;
      }
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    string s(digits.size(), 0);
    vector<int> nums(digits.size());
    for (int i = 0;i < digits.size();++i) {
      int v = digits[i] - '0';
      nums[i] = v;
      s[i] = lstr[v][0];
    }
    vector<string> res;
    while (1) {
      res.push_back(s);
      int u = s.size()-1;
      while (1) {
        char &c = s[u];
        char next_c = next[c];
        if (next_c != -1) {
          c = next_c;
          break;
        } else {
          if(--u < 0) break;
          for (int j = u + 1; j < s.size(); ++j) {
            s[j] = lstr[group[s[j]]][0];
          }
        }
      }
      if (u < 0) break;
    }
    return res;
  }
private:
  char next[256];
  int group[256];
};

int main() {
  string s;
  cin >> s;
  for (string &t : Solution().letterCombinations(s)) {
    cout << t << endl;
  }
  return 0;
}
