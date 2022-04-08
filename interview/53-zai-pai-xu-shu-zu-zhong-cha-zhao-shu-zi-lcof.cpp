class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto hi = upper_bound(lo, nums.end(), target);
        return hi - lo;
    }
};
