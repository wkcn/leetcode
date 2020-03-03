class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 去重
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        for (; j < nums.size(); ++j) {
            if (nums[j] != nums[i])
                nums[++i] = nums[j];
        }
        nums.resize(i+1);
        const int len = nums.size();
        vector<vector<int> > ans;
        ans.push_back({});
        for (int i = 0; i < len; ++i) {
            const int L = ans.size();
            for (int j = 0; j < L; ++j) {
                vector<int> a = ans[j];
                a.push_back(nums[i]);
                ans.emplace_back(a);
            }
        }
        return ans;
    }
};
