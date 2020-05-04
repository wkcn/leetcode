#include "common.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        int start = 0, end = 1;
        // [start, end)
        while (end < size) {
            int ma = 0;
            for (; start < end; ++start) {
                ma = max(nums[start] + start, ma);
            }
            start = end;
            end = ma + 1;
            ++ans;
        }
        return ans;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().jump(nums) << endl;
  return 0;
}
