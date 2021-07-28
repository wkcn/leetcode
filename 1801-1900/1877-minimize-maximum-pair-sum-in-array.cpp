class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // 假如有： a1 < a2 < a3 < a4
        /*
        我们假设(a1, a4), (a2, a3)方式为答案
        假如(a1, a3), (a2, a4)呢?
        有max(a1 + a3, a2 + a4) - max(a1 + a4, a2 + a3)
        a2 + a4一定大于a1 + a4和a2 + a3
         */
         sort(nums.begin(), nums.end());
         const int n = nums.size();
         int ans = nums.front() + nums.back();
         for (int i = 0; i < n / 2; ++i) {
             ans = max(ans, nums[i] + nums[n - i - 1]);
         }
         return ans;
    }
};
