class Solution {
public:
    int massage(vector<int>& nums) {
        // dp[i][约] = dp[i-1][不约] + nums[i];
        // dp[i][不约] = max(dp[i-1][不约], dp[i-1][约]);
        int order = 0, no_order = 0;
        for (int &x: nums) {
            int next_order = no_order + x;
            no_order = max(order, no_order);
            order = next_order;
        }
        return max(order, no_order);
    }
};
