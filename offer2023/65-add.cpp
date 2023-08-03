class Solution {
public:
    int add(int a, int b) {
        // 4 bits
        // -2 + 3 = 1
        // 0b1110 + 0b0011 = 0b0001
        // -2 + 1 = 1
        // 0b1110 + 0b0001 = 0b1111
        // -2 + -3 = -5
        // 0b1110 + 0b1101 = 0b1011
        while (b) {
            int c = a & b;
            a = a ^ b;
            b = (unsigned int)c << 1;
        }
        return a;
    }
};
