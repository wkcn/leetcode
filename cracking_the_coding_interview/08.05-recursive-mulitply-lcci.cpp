class Solution {
public:
    int multiply(int A, int B) {
        int ans = 0;
        unsigned int uA = A;
        unsigned int b = 1;
        for (int i = 0; i < 32; ++i, b <<= 1, uA <<= 1) {
            if (B & b) {
                ans += uA;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int multiply(int A, int B) {
        if (A == 1) return B;
        int halfA = A >> 1;
        int v = multiply(halfA, B);
        v <<= 1; // mul 2
        if (A & 1) v += B;
        return v;
    }
};
