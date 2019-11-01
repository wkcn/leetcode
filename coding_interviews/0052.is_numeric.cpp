#include "common.h"

#define SOLUTION 2

#if SOLUTION == 0
class Solution {
public:
  bool isNumeric(char* string) {
    const int len = strlen(string);
    int i = 0;
    if (!check_sign(string, len, i)) return false;
    if (!check_float(string, len, i)) return false;
    if (i < len && (string[i] == 'e' || string[i] == 'E')) {
      ++i;
      if (!check_sign(string, len, i)) return false;
      if (!check_int(string, len, i)) return false;
    }
    return i == len;
  }
private:
  bool check_sign(char* str, const int len, int &i) {
    if (i >= len) return false;
    if (str[i] == '+') ++i;
    else if (str[i] == '-') ++i;
    return true;
  }
  bool check_float(char* str, const int len, int &i) {
    if (i >= len) return false;
    if (str[i] != '.' && !check_int(str, len, i)) return false;
    if (i < len && str[i] == '.') {
      ++i;
      if (!check_int(str, len, i)) return false;
    }
    return true;
  }
  bool check_int(char* str, const int len, int &i) {
    if (i >= len) return false;
    bool is_num = false;
    for (; i < len; ++i) {
      char &c = str[i];
      if (c >= '0' && c <= '9') {
        is_num = true;
      } else break;
    }
    return is_num;
  }
};
#elif SOLUTION == 1

class Solution {
public:
  const char arr[10] = "+-n.ne+-n";
  const bool turn[10][9] = {
    // +  -  n  .  n  e  +  -  n
      {1, 1, 1, 1, 0, 0, 0, 0, 0}, // start
      {0, 0, 1, 1, 0, 0, 0, 0, 0}, // +
      {0, 0, 1, 1, 0, 0, 0, 0, 0}, // -
      {0, 0, 1, 1, 0, 1, 0, 0, 0}, // n
      {0, 0, 0, 0, 1, 0, 0, 0, 0}, // .
      {0, 0, 0, 0, 1, 1, 0, 0, 0}, // n
      {0, 0, 0, 0, 0, 0, 1, 1, 1}, // e
      {0, 0, 0, 0, 0, 0, 0, 0, 1}, // +
      {0, 0, 0, 0, 0, 0, 0, 0, 1}, // -
      {0, 0, 0, 0, 0, 0, 0, 0, 1}, // n
  };
  bool isNumeric(char* string) {
    int cur = 0;
    for (int i = 0, j; string[i]; ++i) {
      for (j = 0; j < 9; ++j) {
        if (turn[cur][j]) {
          const char& c = string[i];
          const char& p = arr[j];
          if (p == c || (c >= '0' && c <= '9' && p == 'n') || (c == 'E' && p == 'e')) {
            cur = j + 1;
            break;
          }
        }
      }
      if (j == 9) return false;
    }
    return cur == 3 || cur == 5 || cur == 9; 
  }
};

#elif SOLUTION == 2

class Solution {
public:
  bool isNumeric(char* string) {
    std::regex pattern("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
    return regex_match(std::string(string), pattern);
  }
};

#endif

int main() {
  string str;
  cin >> str;
  cout << Solution().isNumeric(const_cast<char*>(str.c_str())) << endl;
  return 0;
}
