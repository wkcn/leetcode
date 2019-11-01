#include "common.h"

// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
class Solution {
public:
  int Add(int num1, int num2) {
    // a: 1011
    // b: 0001
    // s: 1100
    // ^: 1010 
    // &: 0001
    return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
  }
};

int main() {
  int num1, num2;
  cin >> num1 >> num2;
  cout << Solution().Add(num1, num2) << endl;
  return 0;
}
