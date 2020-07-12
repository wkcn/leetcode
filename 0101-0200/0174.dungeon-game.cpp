#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size();
        if (row == 0) return 0;
        const int col = dungeon[0].size();
        if (col == 0) return 0;
        vector<int> dp(col);
        dp[col - 1] = max(-dungeon.back().back() + 1, 1); // 注意这里的+1处理！！
        for (int c = col - 2; c >= 0; --c) {
            dp[c] = max(dp[c + 1] - dungeon.back()[c], 1);
        }
        for (int r = row - 2; r >= 0; --r) {
            dp[col - 1] = max(dp[col - 1] - dungeon[r][col - 1], 1);
            for (int c = col - 2; c >= 0; --c) {
                dp[c] = max(min(dp[c], dp[c+1]) - dungeon[r][c], 1);
            }
        }
        return dp[0];
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size();
        if (row == 0) return 0;
        const int col = dungeon[0].size();
        if (col == 0) return 0;
        vector<vector<int> > rec(row, vector<int>(col, INT32_MAX));
        function<int(int, int)> F;
        F = [&](unsigned int r, unsigned int c) {
            if (r >= row || c >= col) return INT32_MAX; // 下面不会出现同时两个F返回INT32_MAX
            if (rec[r][c] != INT32_MAX) return rec[r][c];
            if (r == row - 1 && c == col - 1) {
                return rec[row-1][col-1] = max(-dungeon[r][c] + 1, 1);
            }
            return rec[r][c] = max(min(F(r + 1, c), F(r, c + 1)) - dungeon[r][c], 1);
        };
        int ans = F(0, 0);
        return ans;
    }
};
#endif

int main() {
  vector<vector<int>> dungeon;
  INPUT_ARRAY2D(dungeon);
  cout << Solution().calculateMinimumHP(dungeon) << endl;
  return 0;
}
