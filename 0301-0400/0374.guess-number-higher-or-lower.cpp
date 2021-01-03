// TODO: 多分查找
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (n == INT32_MAX && guess(INT32_MAX) == 0) return n;
        // n 可能是INT32_MAX
        int lo = 1, hi = min(n, INT32_MAX - 1) + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int g = guess(mid);
            if (g == 0) return mid;
            g > 0 ? lo = mid + 1 : hi = mid;
        }
        return lo;
    }
};

class Solution {
public:
    int guessNumber(int n) {
        // n 可能是INT32_MAX
        // [lo, hi]
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            int g = guess(mid);
            if (g == 0) return mid;
            g > 0 ? lo = mid + 1 : hi = mid - 1;
        }
        return lo;
    }
};
