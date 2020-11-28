class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // 负数标记, 利用更多可利用的空间
        for (int i = 0; i < nums.size(); ++i) {
            int k = abs(nums[i]) - 1;
            if (nums[k] < 0) ans.push_back(abs(nums[i]));
            else nums[k] *= -1;
        }
        return ans;
    }
};
