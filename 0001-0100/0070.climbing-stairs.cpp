// TODO: 使用矩阵乘幂
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int pre = 1, cur = 1, tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur;
    }
};
