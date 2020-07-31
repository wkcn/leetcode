#include "common.h"

class Solution {
public:
    int minArray(vector<int>& numbers) {
        const int size = numbers.size();
        if (size == 0) return 0;
        int lo = 0, hi = size - 1;  // 闭区间
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int val = numbers[mid];
            int rv = numbers[hi]; // 是右边界而不是最右边
            if (val > rv) lo = mid + 1;
            else if (val < rv) hi = mid;
            else --hi;
        }
        return numbers[lo];
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().minArray(nums) << endl;
  return 0;
}
