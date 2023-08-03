class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = 0;
        int ans = 0;
        for (int x : nums) {
            a = max(a + x, x);
            ans = max(ans, a);
        }
        return ans;
    }
};
