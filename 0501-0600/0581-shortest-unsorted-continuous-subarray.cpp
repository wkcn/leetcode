class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        int i = 0;
        while (i + 1 < n && nums[i] <= nums[i + 1]) ++i;
        // nums[:i+1] 是升序
        for (int i2 = i + 1; i2 < n; ++i2) {
            while (i >= 0 && nums[i2] < nums[i]) --i;
        }
        int j = n - 1;
        while (j - 1 >= 0 && nums[j - 1] <= nums[j]) --j;
        // nums[j:]是升序
        for (int j2 = j - 1; j2 >= 0; --j2) {
            while (j < n && nums[j2] > nums[j]) ++j;
        }
        if (i >= j) return 0;
        return j - i - 1;
    }
};
