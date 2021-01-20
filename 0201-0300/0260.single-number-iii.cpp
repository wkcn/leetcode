class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int t = 0;
        for (int x : nums) t ^= x;
        // 当t为INT32_MIN时，不能取其相反数
        int r = (t != INT32_MIN) ? (t & (-t)) : t;
        int a = 0, b = 0;
        for (int x : nums) {
            ((x & r) ? a : b) ^= x;
        }
        return {a, b};
    }
};
