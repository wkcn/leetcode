#include "common.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      if (words.empty()) return {};
      const int wlen = words[0].size();
      const int tlen = wlen * words.size();
      unordered_map<string, int> cnts;
      for (string &s: words) {
        ++cnts[s];
      }
      vector<int> ans;
      for (int t = 0; t < wlen; ++t) {
        unordered_map<string, int> cnts2;
        int need = cnts.size();  // 注意这里是不同单词的数量
        // s[t: t + tlen]
        // 注意下面的if语句包含等于
        if (t + tlen <= s.size()) {
          for (int i = t; i < t + tlen; i += wlen) {
            string r = s.substr(i, wlen);
            auto p = cnts.find(r);
            if (p != cnts.end()) {
              int c = ++cnts2[r];
              if (c == p->second) {
                --need;
              } else if (c == p->second + 1) {
                ++need;
              }
            }
          }
          if (need == 0) {
            ans.push_back(t);
          }
        }
        // 注意判断条件
        for (int i = t + wlen; i + tlen <= s.size(); i += wlen) {
          // s[i: i + tlen]
          string prev = s.substr(i - wlen, wlen);
          auto p = cnts.find(prev);
          if (p != cnts.end()) {
            int c = --cnts2[prev];
            if (c == p->second) {
              --need;
            } else if (c == p->second - 1) {
              ++need;
            }
          }
          string last = s.substr(i + tlen - wlen, wlen);
          p = cnts.find(last);
          if (p != cnts.end()) {
            int c = ++cnts2[last];
            if (c == p->second) {
              --need;
            } else if (c == p->second + 1) {
              ++need;
            }
          }
          if (need == 0) {
            ans.push_back(i);
          }
        }
      }
      return ans;
    }
};

int main() {
  {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    PRINT_ARRAY(Solution().findSubstring(s, words));
  }

  {
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    PRINT_ARRAY(Solution().findSubstring(s, words));
  }

  {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    PRINT_ARRAY(Solution().findSubstring(s, words));
  }
  return 0;
}
