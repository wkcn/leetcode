// NOTE: 好题
// TODO: 继续理解
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int size = nums.size();
        if (size == 0) return 0;
        unordered_map<int, int> ma;
        ma[0] = 1;
        int pre = 0;
        int ans = 0;
        for (int &x : nums) {
            pre += x;
            if (ma.find(pre - k) != ma.end())
                ans += ma[pre - k];
            ++ma[pre];
        }
        return ans;
    }
};
