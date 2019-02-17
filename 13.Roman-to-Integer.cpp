#include "common.h"

class Solution {
public:
  Solution() {
    for (int i = 0; i < 7; ++i) {
      mappings[symbol[i]] = value[i];
    }
  }
  int romanToInt(string s) {
    int res = 0;
    int last = mappings[s[0]];
    for (int i = 0; i < s.size()-1; ++i) {
      int next = mappings[s[i+1]];
      if (last < next) {
        res -= last;
      } else {
        res += last; 
      }
      last = next;
    }
    res += last;
    return res;
  }
private:
  char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  int mappings[256];
  int value[7] = {1, 5, 10, 50, 100, 500, 1000};
};


class Solution2 {
public:
  Solution2() {
    for (int i = 0; i < 7; ++i) {
      mappings[symbol[i]] = i;
    }
  }
  int romanToInt(string s) {
    int res = 0;
    int count = 0;
    int lv = -1;
    for (char c : s) {
      int m = mappings[c];
      if (lv == -1) {
        lv = m;
        count = 1;
      } else {
        if (lv != m) {
          if (m > lv) {
            res += value[m] - value[lv] * count;
            lv = -1;
            count = 0;
          } else {
            res += value[lv] * count;  
            lv = m;
            count = 1;
          }
        } else {
          ++count;
        }
      }
    }
    if (count > 0) {
      res += value[lv] * count;
    }
    return res;
  }
private:
  char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  int mappings[256];
  int value[7] = {1, 5, 10, 50, 100, 500, 1000};
};

int main() {
  Solution so;
  string s;
  while (cin >> s) {
    cout << so.romanToInt(s) << endl;
  }
  return 0;
}
