class Solution {
public:
    bool isPowerOfFour(int n) {
        // 1, 100
        if (n <= 0) return false;
        // 01010101
        return (n & (n-1)) == 0 && (n & 0x55555555);
    }
};
