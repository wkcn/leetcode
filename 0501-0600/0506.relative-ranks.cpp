// 坑, 有可能小于两个人
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> inds(nums.size());
        iota(inds.begin(), inds.end(), 0);
        sort(inds.begin(), inds.end(), [&](const int a, const int b) {
            return nums[a] > nums[b];
        });
        vector<string> ans(nums.size());
        ans[inds[0]] = "Gold Medal";
        if (nums.size() >= 2)
            ans[inds[1]] = "Silver Medal";
        if (nums.size() >= 3)
            ans[inds[2]] = "Bronze Medal";
        for (int i = 3; i < nums.size(); ++i) {
            ans[inds[i]] = to_string(i + 1);
        }
        return ans;
    }
};
