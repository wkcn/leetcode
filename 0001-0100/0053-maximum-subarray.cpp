class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre = max(pre, 0) + nums[i];
            ans = max(ans, pre);
        }
        return ans;
    }
};
