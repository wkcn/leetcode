// 注意数字溢出
class Solution {
using Mat = vector<vector<int>>;
const int MOD = 1000000007;
public:
    int fib(int n) {
        /*
            [F(N)]   [1, 1], [F(n-1)]
                    =
            [F(n-1)] [1, 0], [F(n-2)]
         */
         if (n <= 1) return n;
         Mat A{{1, 1}, {1, 0}};
         Mat c = matpower(A, n - 1);
         return c[0][0];
    }
    Mat matmul(Mat &a, Mat &b) {
        const int n = a.size();
        Mat c(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    c[i][j] += ((long long)a[i][k] * b[k][j]) % MOD;
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }
    Mat matpower(Mat &a, int p) {
        if (p == 1) return a;
        const int n = a.size();
        Mat e(n, vector<int>(n));
        for (int i = 0; i < n; ++i) e[i][i] = 1;
        while (p > 0) {
            if (p & 1) e = move(matmul(e, a));
            a = move(matmul(a, a));
            p >>= 1;
        }
        return e;
    }
};
