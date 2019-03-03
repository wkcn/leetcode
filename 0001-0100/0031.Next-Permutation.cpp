#include "common.h"

/*
 * Runtime: 12 ms, faster than 100.00% of C++ online submissions for Next Permutation.
 * Memory Usage: 10.2 MB, less than 44.59% of C++ online submissions for Next Permutation.
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
          auto pend = nums.rbegin() + (nums.size() - i - 1);
          auto p = upper_bound(nums.rbegin(), pend, nums[i]);
          if (p == pend) {
            std::reverse(nums.begin(), nums.end());
          } else {
            swap(nums[i], *p);
            std::reverse(nums.rbegin(), pend);
          }
          return;
        }
      }
      std::reverse(nums.begin(), nums.end());
    }
};

int main() {
  vector<int> datas;
  Solution so;
  INPUT_ARRAY(datas);
  so.nextPermutation(datas);
  PRINT_ARRAY(datas);
  return 0;
}
