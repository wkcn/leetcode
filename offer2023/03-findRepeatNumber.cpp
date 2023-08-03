class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 共n个数
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
