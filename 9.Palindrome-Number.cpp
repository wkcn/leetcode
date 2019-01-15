#include "common.h"

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int r = x;
      int p = 0;
      while (r > 0) {
        p *= 10;
        p += r % 10;
        r /= 10;
      }
      return p == x; 
    }
};

int main() {
  Solution so;
  cout << so.isPalindrome(121) << endl; 
  cout << so.isPalindrome(10) << endl; 
  return 0;
}
