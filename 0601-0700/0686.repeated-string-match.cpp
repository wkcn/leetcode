#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
// KMP
class Solution {
public:
  int repeatedStringMatch(string a, string b) {
    const int alen = a.size(), blen = b.size();
    vector<int> lps = get_lps(b);
    int i = 0, j = 0;

    /*
     * aabaa
     * aaab
     *
     * aabaaaabaa
     */
    while (i < alen + blen) {
      if (a[i % alen] == b[j]) {
        ++i; ++j;
        if (j >= blen) {
          /*
           * if alen == 3,
           * i, 因为已经++i了
           * 1, 2, 3 -> 1
           * 4, 5, 6 -> 2
           */
          return (i - 1) / alen + 1;
        }
      } else {
        // 这里不能用i >= alen截断，因为后面还会继续尝试匹配
        // 匹配错误了，不意味着当前a[i % alen]的字符不在结果序列中！
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
#elif SOLUTION == 2

// 调用API
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
      const int alen = a.size(), blen = b.size();
      const int max_len = alen + blen - 1; 
      const int repeat = (max_len + alen - 1) / alen; 
      string ra;
      for (int i = 0; i < repeat; ++i) ra += a;
      auto p = ra.find(b);
      if (p == ra.npos) return -1;
      return (p + blen + alen - 1) / alen;
    }
};

#endif

int main() {
  string a, b;
  cin >> a >> b;
  cout << Solution().repeatedStringMatch(a, b) << endl;
  return 0;
}
