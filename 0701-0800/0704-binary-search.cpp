class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            nums[mid] < target ? lo = mid + 1 : hi = mid;
        }
        return lo < nums.size() && nums[lo] == target ? lo : -1;
    }
};
