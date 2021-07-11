#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int, int> cnts;
      cnts[0] = 1;
      int presum = 0;
      int ans = 0;
      for (int x : nums) {
        presum += x;
        auto p = cnts.find(presum - goal);
        if (p != cnts.end())
          ans += p->second; 
        ++cnts[presum];
      }
      return ans;
    }
};
#elif SOLUTION == 1
// TODO 双指针
#endif

int main() {
  vector<int> nums{1,0,1,0,1};
  int goal = 2;
  cout << Solution().numSubarraysWithSum(nums, goal) << endl;
  return 0;
}
