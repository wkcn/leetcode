#include "common.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int size = nums.size();
        if (size <= 0) return {};
        int kind = 1;
        for (int i = 2; i <= size; ++i) kind *= i;
        vector<vector<int> > ans;
        ans.push_back(nums);
        int i;
        for (int k = 1; k < kind; ++k) {
            i = size - 1;
            // nums[i-1] and nums[i]
            while (i >= 1 && nums[i-1] >= nums[i]) --i;
            if (i == 0) {
                reverse(nums.begin(), nums.end());
                ans.push_back(nums);
                continue;
            }
            // nums[i-1] < nums[i]
            int &v = nums[i-1];
            auto re = nums.rbegin() + (size - i); 
            auto p = upper_bound(nums.rbegin(), re, v);
            swap(v, *p);
            reverse(nums.rbegin(), re);
            ans.push_back(nums);
        }
        return ans;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  PRINT_MATRIX(Solution().permute(nums));
  return 0;
}
