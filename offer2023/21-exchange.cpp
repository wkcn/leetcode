class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = (int)nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 != 0) ++i;
            while (i < j && nums[j] % 2 == 0) --j;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
