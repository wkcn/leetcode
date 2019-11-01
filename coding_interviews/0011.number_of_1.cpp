#include "common.h"

#define SOLUTION 2

#if SOLUTION == 0

class Solution {
public:
   int NumberOf1(int n) {
     int m = 0;
     while (n != 0) {
       n &= n - 1;
       ++m;
     }
     return m;
   }
};

#elif SOLUTION == 1

class Solution {
public:
   int NumberOf1(int n) {
     int m = 0;
     if (n < 0) {
       if (n == 0x80000000) return 1;
       n = 0x7FFFFFFF - (-n) + 1;
       ++m; // sign
     }
     while (n != 0) {
       if (n % 2) ++m;
       n /= 2;
     }
     return m;
   }
};

#elif SOLUTION == 2

class Solution {
public:
   int NumberOf1(int n) {
     n = (n & 0b01010101010101010101010101010101) + ((n & 0b10101010101010101010101010101010) >> 1);
     n = (n & 0b00110011001100110011001100110011) + ((n & 0b11001100110011001100110011001100) >> 2);
     n = (n & 0b00001111000011110000111100001111) + ((n & 0b11110000111100001111000011110000) >> 4);
     n = (n & 0b00000000111111110000000011111111) + ((n & 0b11111111000000001111111100000000) >> 8);
     n = (n & 0b00000000000000001111111111111111) + ((n & 0b11111111111111110000000000000000) >> 16);
     return n;
   }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().NumberOf1(n) << endl;
  return 0;
}
