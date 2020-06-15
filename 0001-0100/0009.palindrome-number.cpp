#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> nums;
        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] != nums[j]) return false;
            ++i, --j;
        }
        return true;
    }
};
#elif SOLUTION == 2


// 注意特殊情况x < 0, (x % 10 == 0), x != 0
// 以及数字越界
class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0 || (x % 10 == 0 && x != 0)) return false;
      int y = 0;
      int t;
      while (x > y) {
        t = x % 10;
        x /= 10;
        if (x == y) return true;
        y = y * 10 + t;
      }
      return y == x;
    }
};


#endif

int main() {
  int x;
  cin >> x;
  cout << Solution().isPalindrome(x) << endl;
  return 0;
}
