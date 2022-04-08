class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        array<int, 101> cnts{0};
        for (int x : nums) ++cnts[x];
        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            if (cnts[i] == 1)
                ans += i;
        }
        return ans;
    }
};
