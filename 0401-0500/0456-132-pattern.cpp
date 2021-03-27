#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      const int n = nums.size();
      if (n < 3) return false;
      /*
       * 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j]
       */
      multiset<int> rights;
      int left_min = nums[0];
      for (int i = 2; i < n; ++i) {
        rights.insert(nums[i]);
      }
      for (int i = 1; i < n - 1; ++i) {
        if (nums[i] > left_min) {
          auto p = rights.upper_bound(left_min);
          if (p != rights.end() && *p < nums[i]) {
            return true;
          }
        }
        left_min = min(left_min, nums[i]);
        // 需要传迭代器给erase函数，否则会删除等于这个值的所有元素
        rights.erase(rights.find(nums[i + 1]));
      }
      return false;
    }
};
#elif SOLUTION == 2

// TODO: 单调栈一次遍历的方法
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      // 132
    }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().find132pattern(nums) << endl;
  return 0;
}
