#include "common.h"

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
          if (nums[i] + nums[j] == target) {
            return {i, j};
          }
        }
      }
      return {-1, -1};
    }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution so;
  vector<int> res = so.twoSum(nums, target);
  cout << res[0] << ", " << res[1] << endl;
  return 0;
}
