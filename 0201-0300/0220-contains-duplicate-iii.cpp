#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      set<int> se;
      // 如果nums有下标不同数字相同的两数字, 肯定返回True
      // 对于当前数字nums[i], 如果[nums[i] - t, nums[i] + t]在se中, 则返回True
      for (int i = 0; i < nums.size(); ++i) {
        // nums[i] - t可能越界
        auto it = se.lower_bound(max(nums[i], INT32_MIN + t) - t);
        // nums[i] + t可能越界
        if (it != se.end() && *it <= min(nums[i], INT32_MAX - t) + t) {
          return true;
        }
        se.insert(nums[i]);
        if (i >= k) {
          se.erase(nums[i - k]);
        }
      }
      return false;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      // 桶的大小设为t + 1
      // 原因是如果两个元素在同样的桶里, 一定满足|a - b| <= t
      // 假如在相邻桶里, 有可能满足
      // 如果不相邻, 一定不满足
      unordered_map<int, int> buckets;
      auto B = [&](int v) -> int {
        // 注意映射关系, v < 0时
        // t 可能为0, 并且能避免v = INT32_MIn的情况
        // 目前的实现可能也有bug, 比如t = 0, v = INT32_MIN
        return v >= 0 ? v / (t + 1ll) : (v + 1) / (t + 1ll) - 1;
      };
      for (int i = 0; i < nums.size(); ++i) {
        int x = nums[i];
        int b = B(x);
        auto [p, ok] = buckets.insert({b, x});
        if (!ok) {
          return true;
        } else {
          // 如果是这个桶的第一个元素
          // 目前的实现可能也有bug, 比如t = 0, v = INT32_MIN
          // 看看相邻桶有没有满足条件的数
          if (b != INT32_MIN && buckets.count(b - 1) && x <= t + min(INT32_MAX - t, buckets[b - 1])) return true;
          if (b != INT32_MAX && buckets.count(b + 1) && buckets[b + 1] <= t + min(INT32_MAX - t, x)) return true;
        }
        if (i >= k) {
          buckets.erase(B(nums[i - k]));
        }
      }
      return false;
    }
};
#endif

int main() {
  if (0) {
    vector<int> nums{1, 2, 3, 1};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
  }
  if (0) {
    vector<int> nums{1, 5, 9, 1, 5, 9};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 2, 3) << endl;
  }
  {
    vector<int> nums{INT32_MIN, INT32_MAX};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 2, 0) << endl;
  }
  return 0;
}
