class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        if (len == 0) return;
        int i = len - 1;
        for (; i > 0; --i) {
            if (nums[i - 1] < nums[i]) break;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        auto p = upper_bound(nums.rbegin(), nums.rbegin() + (len - i), nums[i-1]);
        swap(nums[i-1], *p);
        reverse(nums.rbegin(), nums.rbegin() + (len - i));
    }
};
