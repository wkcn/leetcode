class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < n - 2; ++i) { // 要减2！！
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1, k = n - 1;
            // 尝试剪枝
            if (nums[i] + nums[j] * 2 > 0) break;
            if (nums[i] + nums[k] * 2 < 0) continue;
            while (j < k) {
                int su = nums[i] + nums[j] + nums[k];
                if (su == 0) {
                    // 相等时也要更新j和k
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j-1] == nums[j]) ++j;
                    --k;
                    while (j < k && nums[k] == nums[k+1]) --k;      
                } else if (su < 0) {
                    ++j;
                    while (j < k && nums[j-1] == nums[j]) ++j;
                } else {
                    --k;
                    while (j < k && nums[k] == nums[k+1]) --k;
                }
            }
        }
        return ans;
    }
};
