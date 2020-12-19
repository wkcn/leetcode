#include "common.h"

// KMP
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


int main() {
  string haystack, needle;
  cin >> haystack >> needle;
  cout << Solution().strStr(haystack, needle) << endl;
  return 0;
}
