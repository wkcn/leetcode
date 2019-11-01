#include "common.h"

#if 1

class Solution {
public:
    int myAtoi(string str) {
      int i = find_non_white(str, 0);
      if (i >= str.size()) return 0;
      char c = str[i];
      bool neg = false;
      if (c == '-' || c == '+') {
        neg = (c == '-');
        ++i;
        if (i >= str.size()) return 0;
        c = str[i];
      }
      if (c >= '0' && c <= '9') {
        // digit
        int res = 0;
        do {
          int e = c - '0';
          if (res - INT_MAX / 10 + (e > 7) > 0) {
            return neg ? INT_MIN : INT_MAX;
          }
          res *= 10;
          res += c - '0';
          if (res < 0) return neg ? INT_MIN : INT_MAX;
          ++i;
          if (i >= str.size()) break;
          c = str[i];
        } while (c >= '0' && c <= '9');
        if (neg) res = -res;
        return res;
      }
      return 0;
    }
private:
    int find_non_white(const string &s, int start) {
      for (int i = start; i < s.size(); ++i) {
        if (s[i] != ' ') return i;
      }
      return s.size();
    }
};

#else

class Solution {
public:
  int myAtoi(string str) {
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
    for (; i < len; ++i) {
      char c = str[i];
      if (c >= '0' && c <= '9') {
        int e = flag * (c - '0');
        if (flag < 0) {
          if (s < (INT_MIN - e) / 10) return INT_MIN; 
        } else
          if (s > (INT_MAX - e) / 10) return INT_MAX; 
        s *= 10;
        s += e;
      } else break;
    }
    return s;
  }
};


#endif

int main() {
  Solution so;
  /*
  cout << so.myAtoi("42") << endl;
  cout << so.myAtoi("   -42") << endl;
  cout << so.myAtoi("4193 with words") << endl;
  cout << so.myAtoi("words and 987") << endl;
  cout << so.myAtoi("-91283472332") << endl;
  */
  cout << so.myAtoi("-2147483648") << endl;
  //cout << so.myAtoi("2147483648") << endl;
  //cout << so.myAtoi("2147483646") << endl;
  return 0;
}
