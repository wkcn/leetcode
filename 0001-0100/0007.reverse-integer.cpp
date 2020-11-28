class Solution {
public:
    int reverse(int x) {
        bool minus = x < 0;
        if (!minus) x = -x;
        int v = 0;
        while (x < 0) {
            int a = x % 10; x /= 10;
            // v * 10 + a
            if (v < INT32_MIN / 10) return 0;
            if (v * 10 < INT32_MIN - a) return 0;
            v = v * 10 + a;
        }
        if (minus) return v;
        if (v == INT32_MIN) return 0;
        return -v;
    }
};
