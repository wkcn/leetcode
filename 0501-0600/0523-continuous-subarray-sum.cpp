#include "common.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      // 前缀和 + 取模
      if (nums.size() < 2) return false;
      if (k == 1) return true;
      // 需要记录前缀和的下标, 使得最短长度能达到2
      unordered_map<int, int> se;
      se[0] = -1;
      int pre = 0;
      for (int i = 0; i < nums.size(); ++i) {
        pre = (pre + nums[i]) % k;
        auto p = se.insert({pre, i});
        if (!p.second) {
          int pi = p.first->second;
          if (i - pi >= 2) {
            return true;
          }
        }
      }
      return false;
    }
};

int main() {
  {
    vector<int> nums{1, 0};
    int k = 2;
    cout << Solution().checkSubarraySum(nums, k) << endl;
  }
  {
    vector<int> nums{23, 2, 4, 6, 7};
    int k = 6;
    cout << Solution().checkSubarraySum(nums, k) << endl;
  }
  {
    vector<int> nums{23, 2, 6, 4, 7};
    int k = 6;
    cout << Solution().checkSubarraySum(nums, k) << endl;
  }
  {
    vector<int> nums{23, 2, 6, 4, 7};
    int k = 13;
    cout << Solution().checkSubarraySum(nums, k) << endl;
  }
  return 0;
}
