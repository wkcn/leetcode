class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 0101 = 0x5, 1010 = 0xA
        n = (n & 0x55555555) + ((n & 0xAAAAAAAA) >> 1);
        // 0011 = 0x3, 1100 = 0xC
        n = (n & 0x33333333) + ((n & 0xCCCCCCCC) >> 2);
        // 00001111 = 0x0F, 11110000 = 0xF0
        n = (n & 0x0F0F0F0F) + ((n & 0xF0F0F0F0) >> 4);
        n = (n & 0x00FF00FF) + ((n & 0xFF00FF00) >> 8);
        n = (n & 0xFFFF) + ((n & 0xFFFF0000) >> 16);
        return n;
    }
};
