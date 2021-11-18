class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int pre = nums[0];
        int ans = pre;
        for (int i = 1; i < nums.size(); ++i) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};
