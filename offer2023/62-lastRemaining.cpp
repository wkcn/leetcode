class Solution {
public:
    int lastRemaining(int n, int m) {
        // f(n)表示n个人编号，最后一个数字的编号
        // f(n) = (f(n-1) + m) % n
        // f(1) = 0
        int e = 0;
        for (int i = 2; i <= n; ++i) {
            e = (e + m) % i;
        }
        return e;
    }
};
