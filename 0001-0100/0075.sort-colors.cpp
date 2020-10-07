// TODO 其他两种一遍过的方法
class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int len = nums.size();
        int p0 = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 0) {
                swap(nums[p0++], nums[i]);
            }
        }
        int p1 = p0;
        for (int i = p0; i < len; ++i) {
            if (nums[i] == 1) {
                swap(nums[p1++], nums[i]);
            }
        }
    }
};
