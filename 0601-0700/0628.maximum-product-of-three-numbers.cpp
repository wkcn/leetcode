class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 3个正，或者1正2负
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(), nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};
