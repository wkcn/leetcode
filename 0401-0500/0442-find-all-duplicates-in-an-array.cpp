class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] != i + 1) {
                if (nums[nums[i] - 1] == nums[i]) {
                    ans.push_back(nums[i]);
                    nums[i] = -nums[i];
                    break;
                } else {
                    swap(nums[nums[i] - 1], nums[i]);
                }
            }
        }
        return ans;
    }
};
