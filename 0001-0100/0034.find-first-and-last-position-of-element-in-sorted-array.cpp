int my_lower_bound(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        nums[mid] < target ? lo = mid + 1 : hi = mid;
    }
    return lo;
}

int my_upper_bound(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        nums[mid] <= target ? lo = mid + 1 : hi = mid;
    }
    return lo;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = my_lower_bound(nums, target);
        int hi = my_upper_bound(nums, target);
        if (lo == nums.size() || nums[lo] != target) return {-1, -1};
        return {lo, --hi};
    }
};
