class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int v = 0;
        for (int &x : nums) v ^= x;
        return v;
    }
};
