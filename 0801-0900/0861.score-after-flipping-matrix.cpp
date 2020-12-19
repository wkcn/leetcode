class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // 每行第一个元素必须为1
        // 可以先翻转行， 再翻转列
        // 任意最优翻转序列， 最终结果不变
        const int R = A.size();
        const int C = A[0].size();
        int ans = (R << (C - 1));
        if (C >= 2) {
            int base = 1 << (C - 2); // start at c = 1
            for (int c = 1; c < C; ++c) {
                int ones = 0;
                for (int r = 0; r < R; ++r) {
                    if (!(A[r][0] ^ A[r][c])) ++ones;
                }
                ones = max(ones, R - ones);
                ans += (base * ones);
                base >>= 1;
            }
        }
        return ans;
    }
};
