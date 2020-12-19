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

#elif SOLUTION == 3

// reference: https://leetcode-cn.com/problems/implement-strstr/solution/bang-ni-ba-kmpsuan-fa-xue-ge-tong-tou-ming-ming-ba/
class Solution {
public:
    int strStr(string haystack, string needle) {
      // 注意处理空字符串
      if (needle.empty()) return 0;
      vector<int> prefix(needle.size(), 0);
#if 0
      // 最简单的版本
      for (int i = 0; i < needle.size(); ++i) {
        // 长度短不匹配时，长度长的可能匹配；因为前缀后缀都是从左往右读！！
        for (int k = i; k > 0; --k) {
          if (needle.substr(0, k) == needle.substr(i - k + 1, k)) {
            prefix[i] = k;
            break;
          }
        }
      }
#else
      {
        prefix[0] = 0;
        int i = 0, j = 1;
        while (j < needle.size()) {
          if (needle[i] == needle[j]) {
            prefix[j] = i + 1;
            ++i;
            ++j;
          } else {
            // 好好领会，指针为什么这么跳
            if (i == 0) prefix[j++] = 0;
            else i = prefix[i - 1];
          }
        }
      }
#endif
      // PRINT_ARRAY(prefix);
      int i = 0, j = 0;
      while (i < haystack.size()) {
        // cout << i << ", " << j << endl;
        // cout << haystack[i] << " vs " << needle[j] << endl;
        if (haystack[i] == needle[j]) {
          if (++j == needle.size()) return i - needle.size() + 1;
          ++i;
        } else {
          if (j > 0) {
            // 是直接赋值！！
            j = prefix[j - 1];
            // 要看下一回合是否和haystack[i]匹配
          } else ++i;
        }
      }
      return -1;
    }
};


#endif

int main() {
  string haystack, needle;
  cin >> haystack >> needle;
  cout << Solution().strStr(haystack, needle) << endl;
  return 0;
}
