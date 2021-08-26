class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1; ++j) {
                // k will be greater than j
                while (k < n && nums[i] + nums[j] > nums[k]) ++k;
							  // NOTICE
                ans += max(k - j - 1, 0);
            }
        }
        return ans;
    }
};
