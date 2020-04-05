#if SOLUTION == 1
class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
            n = 5, m = 3
            0, 1, 2, 3, 4
            0, 1, 3, 4
            1, 3, 4
            1, 3
            3
         */
         /*
            n = 5, m = 2
            0, 1, 2, 3, 4
            0, 2, 3, 4
            0, 2, 4
            2, 4
            2
          */
         if (n == 1) return 0;
         int r = n % m;
         // 是加m
         return (lastRemaining(n-1, m) + m) % n;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int lastRemaining(int n, int m) {
        // f(1) = 0
        // f(n) = (f(n-1) + m) % n
        int v = 0;
        for (int i = 2; i <= n; ++i) {
            v = (v + m) % i;
        }
        return v;
    }
};
#endif
