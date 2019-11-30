// notice: the type of <string>.size) is unsigned int!!!!!!
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 0
class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      int si = haystack.size() - needle.size() + 1;
      for (int i = 0; i < si; ++i) {
        int j;
        for (j = 0; j < needle.size(); ++j) {
          if (haystack[i + j] != needle[j]) break;
        }
        if (j == needle.size()) return i;
      }
      return -1;
    }
};
#elif SOLUTION == 1

class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      int i = 0, j = 0;
      while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
          ++i; ++j;
          if (j >= needle.size()) return i - j;
        } else {
          i = i - j + 1;
          j = 0;
        }
      }
      return -1;
    }
};

#elif SOLUTION == 2

// Reference:
// https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

class Solution {
public:
  int strStr(string haystack, string needle) {
    int hlen = haystack.size(), nlen = needle.size();
    if (nlen <= 0) return 0;
    vector<int> lps = get_lps(needle);
    int i = 0, j = 0;

    while (i < hlen) {
      if (haystack[i] == needle[j]) {
        ++i; ++j;
        if (j >= nlen) return i - j;
      } else {
        j ? j = lps[j - 1] : ++i;
      }
    }
    return -1;
  }
private:
  vector<int> get_lps(const string &needle) {
    vector<int> lps(needle.size());
    lps[0] = 0;
    int i = 1, len = 0;
    int slen = needle.size();
    while (i < slen) {
      if (needle[i] == needle[len]) {
        lps[i++] = ++len;
      } else {
        len ? len = lps[len - 1] : lps[i++] = 0;
      }
    }
    return lps;
  }
};

#endif

int main() {
  string haystack, needle;
  cin >> haystack >> needle;
  cout << Solution().strStr(haystack, needle) << endl;
  return 0;
}
