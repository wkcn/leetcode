class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 可以等价一个元素减1
        int mi = *min_element(nums.begin(), nums.end());
        using LL = long long;
        LL ans = 0;
        for (int x : nums) {
            ans += (LL)x - mi;
        }
        return ans;
    }
};
