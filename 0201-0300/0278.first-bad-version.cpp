// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // n 可能是INT32_MAX
        unsigned int lo = 1, hi = (unsigned int)n + 1u;
        while (lo < hi) {
            unsigned int mid = lo + ((hi - lo) >> 1);
            isBadVersion(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
};
