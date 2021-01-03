class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int v = x ^ y;
        int ans = 0;
        while (v != 0) {
            v &= (v - 1);
            ++ans;
        }
        return ans;
    }
};
