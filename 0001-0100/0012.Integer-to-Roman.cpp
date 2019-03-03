#include "common.h"

class Solution {
public:
  string intToRoman(int num) {
    string buffer;
    int k = 0;
    while (num > 0) {
      string y;
      int v = num % 10;
      num /= 10;
      if (v <= 3) {
        for (int i = 0;i < v;++i) {
          y += symbol[k];
        }
      } else if (v == 4) {
        y += symbol[k];
        y += symbol[k+1];
      } else if (v <= 8) {
        y += symbol[k+1];
        for (int i = 5; i < v; ++i) {
          y += symbol[k];
        }
      } else {
        for (int i = v; i < 10; ++i) {
          y += symbol[k];
        }
        y += symbol[k + 2];
      }

      buffer = y + buffer;
      k += 2;
    }
    return buffer;
  }
private:
  char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  int value[7] = {1, 5, 10, 50, 100, 500, 1000};
};

int main() {
  Solution so;
  for (int i = 1; i <= 100; ++i) {
    cout << i << ": " << so.intToRoman(i) << endl;
  }
  return 0;
}
