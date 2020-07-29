// TODO: DP
#include "common.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        typedef unsigned long long ULL;
        // 注意用int会溢出
        ULL su = accumulate(nums.begin(), nums.end(), ULL(0));
        ULL lo = 1, hi = su; // su可能是INT32_MAX !!!!
        // [lo, hi]
        const int len = nums.size();
        while (lo < hi) {
            ULL mid = lo + ((hi - lo) >> 1);
            ULL acc = 0;
            int i = 0, e = 0;
            for (; e < m && i < len; ++e) {
                while (i < len) {
                    acc += nums[i];
                    if (acc > mid) {
                        acc = 0;
                        break;
                    }
                    ++i;
                }
            }
            // e >= m || i >= len
            i < len ? lo = mid + 1 : hi = mid;
        }
        return lo;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int m; cin >> m;
  cout << Solution().splitArray(nums, m) << endl;
  return 0;
}
