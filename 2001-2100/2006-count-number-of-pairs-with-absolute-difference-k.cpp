class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // nums[j] = nums[i] - k or nums[i] + k
        unordered_map<int, int> cnts;
        int ans = 0;
        for (int x : nums) {
            ans += cnts[x];
            ++cnts[x - k];
            if (k > 0) ++cnts[x + k];
        }
        return ans;
    }
};
