class Solution {
public:
    int exchangeBits(int num) {
        // 00 -> 00    +00
        // 01 -> 10    +01
        // 10 -> 01    +11
        // 11 -> 11    +00
        const int mask = 0x55555555; // 0b0101
        return ((num&mask)<<1) | ((num>>1)&mask);
    }
};
