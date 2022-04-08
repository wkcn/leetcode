class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 数字取值为100
        int su = accumulate(nums.begin(), nums.end(), 0);
        array<int, 201> cnts{0};
        for (int x : nums) ++cnts[x + 100];
        for (int i = -100; i <= -1 && k > 0; ++i) {
            if (cnts[i + 100] > 0) {
                int f = min(k, cnts[i + 100]);
                k -= f;
                cnts[i + 100] -= f;
                cnts[-i + 100] += f;
                su += -i * 2 * f;
            }
        }
        if (k % 2 == 0) return su;
        for (int i = 0; i <= 100; ++i) {
            if (cnts[i + 100] > 0) {
                su -= i * 2;
                break;
            }
        }
        return su;
    }
};
