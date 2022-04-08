class Solution {
public:
    int arrangeCoins(int n) {
        /*
            假设能构成完整K行
            (1 + K) * K / 2 <= n
            如何估计K的上下界？
            K * K / 2 < (1 + K) * K / 2 < (1 + K) * (1 + K) / 2
            K * K / 2 < n, K < sqrt(2 * n)
         */
         int lo = 0, hi = sqrt(2 * (long long)n) + 1;
         while (lo < hi) {
             int mid = lo + ((hi - lo) >> 1);
             (1 + (long long)mid) * (long long)mid / 2 <= n ? lo = mid + 1 : hi = mid;
         }
         return --lo;
    }
};
