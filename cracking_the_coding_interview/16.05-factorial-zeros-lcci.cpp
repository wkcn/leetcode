#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int u = 5;
        while (1) {
            ans += n / u;
            if (u <= n / 5) u *= 5; // 防止u * 5溢出
            else break;
        }
        return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
          n /= 5;
          ans += n;
        }
        return ans;
    }
};
#endif
