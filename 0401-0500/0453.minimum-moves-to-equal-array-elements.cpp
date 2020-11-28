class Solution {
public:
    int minMoves(vector<int>& nums) {
        // n - 1个元素加1, 可以看成1个元素减1
        int mi = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int x : nums) ans += x - mi;
        return ans;
    }
};
