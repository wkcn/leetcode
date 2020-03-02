class Solution {
public:
    int reverseBits(int num) {
        int t = 0, f = 0; // t翻,f不翻
        int best = 0;
        unsigned int b = 1;
        for (int i = 0; i < 32; ++i, b <<= 1) {
            if (num & b) {
                f = f + 1;
                t = t + 1;
            } else {
                t = f + 1;
                f = 0;
            }
            if (t > best) best = t;
        }
        return best;
    }
};
