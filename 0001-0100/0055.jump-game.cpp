class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int s = 0;
        for (int i = 0; i < n && i <= s; ++i) {
            s = max(s, nums[i] + i);
        }
        return s >= n-1;
    }
};
