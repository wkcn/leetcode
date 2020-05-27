#include "common.h"

// TODO: 二进制和链表
// 注意, 重复的数字可以出现多次

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cnt[i] = len(filter(lambda x: x <= i, nums)), 1 <= i <= n
        // [1, target) cnt[i] = i
        // [target, n] cnt[i] > i
        
        // 如何理解样例：[1, 1] ?
        int lo = 1, hi = nums.size(); // nums.size() == n + 1
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int cnt = 0;
            for (int &x : nums) {
                cnt += x <= mid;
            }
            cnt > mid ? hi = mid : lo = mid + 1; 
        }
        return lo;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().findDuplicate(nums) << endl;
  return 0;
}
