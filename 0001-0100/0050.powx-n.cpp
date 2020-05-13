class Solution {
public:
    double myPow(double x, int n) {
        double f;
        if (n > 0) {
            n = -n;
            f = x;
        } else {
            f = 1.0 / x;
        }
        double r = 1.0;
        while (n < 0) {
            if (n % 2 != 0) r *= f;
            f *= f;
            n /= 2;
        }
        return r;
    }
};
