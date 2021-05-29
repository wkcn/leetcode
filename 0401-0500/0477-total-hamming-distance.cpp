class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for (unsigned int i = 1 << 31; i > 0; i >>= 1) {
            int one = 0;
            for (int x : nums) if (x & i) ++one;
            ans += one * (n - one);
        }
        return ans;
    }
};
