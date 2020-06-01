class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int cur = nums[0], prev = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = cur;
            cur = max(prev + nums[i], cur);
            prev = tmp;
        }
        return cur;
    }
};
