class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int v = 0;
        for (int &x : nums) v ^= x;
        v &= -v;
        int a = 0, b = 0;
        for (int &x : nums) {
            if (x & v) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};
