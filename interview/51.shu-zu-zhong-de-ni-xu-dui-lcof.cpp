// TODO: 树状数组
#include "common.h"

int tmp[50001];
class Solution {
public:
    int reversePairs(vector<int>& nums) {
      return reversePairs(nums, 0, nums.size());
    }
    int reversePairs(vector<int>& nums, int start, int end) {
      if (end - start <= 1) return 0;
      int mid = start + ((end - start) >> 1);
      int ans = reversePairs(nums, start, mid);
      ans += reversePairs(nums, mid, end);
      memcpy(tmp + start, nums.data() + start, (mid - start) * sizeof(int));
      int i = start, j = mid;
      int k = start;
      while (i < mid && j < end) {
        while (i < mid && (j >= end || tmp[i] <= nums[j])) nums[k++] = tmp[i++];
        while (j < end && (i >= mid || tmp[i] > nums[j])) {
          ans += mid - i;
          nums[k++] = nums[j++];
        }
      }
      if (i < mid) memcpy(nums.data() + k, tmp + i, (mid - i) * sizeof(int));
      return ans;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().reversePairs(nums) << endl;
  PRINT_ARRAY(nums);
  return 0;
}
