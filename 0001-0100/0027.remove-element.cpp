#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size();
        while (i < j) {
            if (nums[i] == val) {
                nums[i] = nums[j - 1];
                --j;
            } else
                ++i;
        }
        return j;
    }
};
#endif

int main() {
  vector<int> nums; int val;
  INPUT_ARRAY(nums);
  cin >> val;
  cout << Solution().removeElement(nums, val) << endl;
  return 0;
}
