class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower_bound, 找到第一个大于或等于target的值的下标
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            nums[mid] < target ? lo = mid + 1 : hi = mid;
        }
        return lo;
    }
};
