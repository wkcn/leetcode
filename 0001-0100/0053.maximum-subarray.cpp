// TODO: 分治法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int size = nums.size();
        if (size <= 0) return 0;
        int best = nums[0];
        int t = nums[0];
        for (int i = 1; i < size; ++i) {
            t = max(nums[i], nums[i] + t);
            best = max(t, best);
        }
        return best;
    }
};
