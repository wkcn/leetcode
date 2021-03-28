class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // AB -> B^T A^T
        // 分治
        // 16 bits
        n = (n >> 16) | (n << 16);
        // 8 bits
        n = ((n & M8) << 8) | ((n >> 8) & M8);
        n = ((n & M4) << 4) | ((n >> 4) & M4);
        n = ((n & M2) << 2) | ((n >> 2) & M2);
        n = ((n & M1) << 1) | ((n >> 1) & M1);
        return n;
    }
private:
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M4 = 0x0f0f0f0f;
    const uint32_t M8 = 0x00ff00ff;
};
