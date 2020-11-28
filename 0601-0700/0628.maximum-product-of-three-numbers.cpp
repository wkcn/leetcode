class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 三个正数, 或者一正两负
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(), nums.back() * nums[n - 2] * nums[n - 3]);
    }
};
