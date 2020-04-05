// TODO: Multiple kind of sort algorithms
#include "common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        my_quicksort(nums, 0, nums.size()-1);
        return nums;
    }
    void my_quicksort(vector<int> &nums, int start, int end) {
        if (start >= end) return;
        int i = start, j = end;
        int p = nums[start];
        while (i < j) {
            while (i < j && nums[j] >= p) --j;
            nums[i] = nums[j];
            while (i < j && nums[i] <= p) ++i;
            nums[j] = nums[i];
        }
        nums[i] = p;
        my_quicksort(nums, start, i-1);
        my_quicksort(nums, i+1, end);
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution().sortArray(nums);
  PRINT_ARRAY(nums);
  return 0;
}
