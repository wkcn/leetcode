class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            nums[mid] > mid ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
};
