#include "common.h"

// 需要判断是否越界，以及处理INT32_MIN
class Solution {
public:
  int StrToInt(string str) {
    int i = 0;
    const int len = str.size();
    while (i < len && str[i] == ' ') ++i;
    int flag = 1;
    if (str[i] == '+') ++i;
    else if (str[i] == '-') {
      flag = -1;
      ++i;
    }
    int s = 0;
    int last_flag = 0;
    for (; i < len; ++i) {
      char c = str[i];
      if (c >= '0' && c <= '9') {
        int e = flag * (c - '0');
        if (s > 0) last_flag = 1;
        else if (s < 0) last_flag = -1;
        s *= 10;
        s += e;
        if (s > 0 && last_flag == -1) return 0;
        if (s < 0 && last_flag == 1) return 0;
      } else return 0;
    }
    return s;
  }
};

int main() {
  cout << INT32_MIN << endl;
  string s;
  cin >> s;
  cout << Solution().StrToInt(s) << endl;
  return 0;
}
