#include "common.h"

class Solution {
public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + abs(nums1[i] - nums2[i])) % MOD;
    }
    // 用nums1[j]替换nums1[i]
    // ans的变化 ans + diff: diff = abs(nums1[j] - nums2[i]) - abs(nums1[i] - nums2[i])
    // 右边部分对于位置i为固定值
    // minimize diff
    vector<int> ns(nums1.begin(), nums1.end());
    sort(ns.begin(), ns.end());
    int min_diff = INT32_MAX;
    for (int i = 0; i < n; ++i) {
      auto p = lower_bound(ns.begin(), ns.end(), nums2[i]);
      // nums2[i] <= *p
      int m = INT32_MAX;
      if (p != ns.begin()) {
        m = min(m, abs(*(p - 1) - nums2[i]));
      }
      if (p != ns.end()) {
        m = min(m, abs(*(p) - nums2[i]));
      }
      if (m != INT32_MAX)
        min_diff = min(min_diff, m - abs(nums1[i] - nums2[i])); 
    }

    if (min_diff > 0) return ans;
    return (ans + min_diff + MOD) % MOD;
  }
private:
  const int MOD = int(1e9) + 7;
};

int main() {
  {
  vector<int> nums1{1,7,5};
  vector<int> nums2{2,3,5};
  cout << Solution().minAbsoluteSumDiff(nums1, nums2) << endl;
  }
  {
  vector<int> nums1{1,10,4,4,2,7};
  vector<int> nums2{9,3,5,1,7,4};
  cout << Solution().minAbsoluteSumDiff(nums1, nums2) << endl;
  }
  return 0;
}
