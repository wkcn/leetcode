#include "common.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      bool used[3]{false};
      int top[3];
      for (int x : nums) {
        for (int i = 0; i < 3; ++i) {
          if (!used[i]) {
            used[i] = true;
            top[i] = x;
            break;
          } else if (x > top[i]) {
            for (int k = 2; k >= i + 1; --k) {
              // 转移数字时, 记得检查标记
              if (used[k - 1]) {
                top[k] = top[k - 1];
                used[k] = true;
              }
            }
            top[i] = x;
            break;
          } else if (x < top[i]) {
            continue;
          } else break; // top[i] == x
        }
      }
      return used[2] ? top[2] : top[0];
    }
};


int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().thirdMax(nums) << endl;
  return 0;
}
