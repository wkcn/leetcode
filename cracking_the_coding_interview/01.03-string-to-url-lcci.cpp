/*
 * 坑死我了
 * 1. S的长度>=最终字符串长度
 * 2. 原字符串为S[:length]
 */
#include "common.h"

class Solution {
public:
    string replaceSpaces(string S, int length) {
      int i = length - 1;
      int cnt = 0; for (int i = 0; i < length; ++i) if (S[i] == ' ') ++cnt;
      int new_len = length + 2 * cnt;
      S[new_len] = 0;
      int j = new_len - 1;
      for (; i >= 0; --i) {
        if (S[i] == ' ') {
          S[j--] = '0';
          S[j--] = '2';
          S[j--] = '%';
        } else S[j--] = S[i];
      }
      return S;
    }
};

int main() {
  string S = "Mr John Smith    ";
  int length = 13;
  cout << Solution().replaceSpaces(S, length) << endl;
  return 0;
}
