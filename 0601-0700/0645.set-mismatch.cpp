// TODO: xor的方法
#include "common.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return {nums[i], i + 1};
        }
        return {};
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  PRINT_ARRAY(Solution().findErrorNums(nums));
  return 0;
}

#if 0
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        int v = 0;
        for (int i = 1; i <= n; ++i) v ^= i;
        for (int x : nums) v ^= x;
        // 此时, v是重复数字a和缺失b的数字的异或
        int l = v & (-v); // 两个数字只有后面一位不一样
        // l 中有一位为1, 分别对nums和[1, n]分为两组
        // 对于存在1的组, 假如a在1组, 那么b在0组
        /*
            a因为出现两次, a ^ a = 0
            因此1组中异或结果为a
            由于b在0组, 异或结果为b
         */
        // 如果a在0组, 那么b在1组
        // 区分不出a在0组还是1组, 因此要进行二次检查
        int a = 0;
        for (int i = 1; i <= n; ++i) if (i & l) a ^= i;
        for (int x : nums) if (x & l) a ^= x;
        int b = v ^ a;
        for (int x : nums) {
            if (x == a) return {a, b};
        }
        return {b, a};
    }
};
#endif
