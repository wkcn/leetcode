#include "common.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int v = nums[i];
            if (v >= 1 && v <= nums.size() && nums[v-1] != v) {
                swap(nums[v-1], nums[i]);
            } else ++i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().firstMissingPositive(nums) << endl;
  return 0;
}
