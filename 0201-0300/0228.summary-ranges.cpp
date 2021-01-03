class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j;
        vector<string> ans;
        while (i < nums.size()) {
            for (j = i + 1; j < nums.size() && nums[j - 1] + 1 == nums[j]; ++j);
            // [i, j)
            if (nums[i] == nums[j - 1]) ans.push_back(to_string(nums[i]));
            else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            i = j;
        }
        return ans;
    }
};
