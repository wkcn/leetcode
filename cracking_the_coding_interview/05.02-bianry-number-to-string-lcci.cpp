#include "common.h"

class Solution {
public:
    string printBin(double num) {
        string s = "0.";
        double su = 0;
        double k = 1;
        // 审题啊，题目是问32位二进制！
        for (int i = 0; i < 32 && su != num; ++i) {
            k /= 2;
            double h = su + k;
            if (h <= num) {
                s += '1';
                su = h;
            } else {
                s += '0';
            }
        }
        if (su != num) return "ERROR";
        return s;
    }
};

int main() {
  double a = 0.125, b = 0.5;
  double c = a + b;
  double d = 0.625;
  double e = 0.24247975418376266;
  cout << a << ": " << HEX2STR(a) << endl;
  cout << b << ": " << HEX2STR(b) << endl;
  cout << c << ": " << HEX2STR(c) << endl;
  cout << d << ": " << HEX2STR(d) << endl;
  cout << d << ": " << HEX2STR(d) << endl;
  cout << e << ": " << HEX2STR(e) << endl;
  return 0;
}
