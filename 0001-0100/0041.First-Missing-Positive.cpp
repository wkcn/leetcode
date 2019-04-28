#include "common.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      const int n = nums.size();
      for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) 
          swap(nums[i], nums[nums[i] - 1]);
      }
      for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) return i + 1;
      }
      return n + 1;
    }
};

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  cout << Solution().firstMissingPositive(vs) << endl;
  return 0;
}
