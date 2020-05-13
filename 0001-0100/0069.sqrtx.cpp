class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int lo = 1, hi = x / 2 + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            mid <= x / mid ? lo = mid + 1 : hi = mid; // 直接用mid * mid <= x会溢出
        }
        return --lo;
    }
};
