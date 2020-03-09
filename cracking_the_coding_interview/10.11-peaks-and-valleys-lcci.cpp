class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int len = nums.size();
        for (int i = 1; i < len; ++i) {
            if (i & 1) {
                // 谷
                if (nums[i-1] < nums[i]) swap(nums[i-1], nums[i]);
            } else {
                if (nums[i-1] > nums[i]) swap(nums[i-1], nums[i]);
            }
        }
    }
};
