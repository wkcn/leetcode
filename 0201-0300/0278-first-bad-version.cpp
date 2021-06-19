// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == INT32_MAX) {
            if (isBadVersion(n) && !isBadVersion(n)) return n;
            --n;
        }
        int lo = 1, hi = n + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            isBadVersion(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
};
