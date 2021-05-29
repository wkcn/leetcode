#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
// FIX3: 第一个维度改成101, 原因不明(100, 20, 100)
int dp[101][101][21];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      /*
       * 状态:
       *     最小花费: dp[i][g][c]
       *     当前已经涂完下标为i的房子, 下标为i的房子现在的颜色为c, 目前组成的街区数为g
       *     if houses[i] == 0 {
       *         // 需要涂色
       *         dp[i][g][c] = min(dp[i-1][g][j| j=c], dp[i-1][g-1][j | j != c]) + cost[i][j]
       *     } else {
       *         dp[i][g][houses[i]] = min(dp[i - 1][g][houses[i]], dp[i - 1][g-1][c] (c != houses[i]))
       *         others: INT32_MAX
       *     } 
       */
       // init
       // 这里会越界dm[m], 对应FIX3
       fill(dp[0][0], dp[m][0], INT32_MAX);
       if (houses[0] == 0) {
         for (int j = 0; j < n; ++j) {
           dp[0][1][j] = cost[0][j];
         }
       } else {
         dp[0][1][houses[0] - 1] = 0;
       }
       for (int i = 1; i < m; ++i) {
         if (houses[i] == 0) {
           // 绘制同样的颜色, g不增加
           for (int g = 1; g <= min(i, target); ++g) {
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g][j];
               if (v != INT32_MAX) v += cost[i][j];
               dp[i][g][j] = v;
             }
           }
           // 绘制不同的颜色, g增加
           for (int g = 2; g <= min(i + 1, target); ++g) {
             // find the top-2 of dp[i - 1][g - 1][j]
             int top1_v = INT32_MAX, top1_j = -1;
             int top2_v = INT32_MAX, top2_j = -1;
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g - 1][j];
               if (v < top1_v) {
                 top2_v = top1_v; top2_j = top1_j;
                 top1_v = v; top1_j = j;
               } else if (v < top2_v) {
                 top2_v = v; top2_j = j;
               }
             }
             if (top1_v == INT32_MAX) continue;
             // update dp[i][g][j]
             for (int j = 0; j < n; ++j) {
               if (top1_j != j) {
                 // FIX2: 需要加min
                 dp[i][g][j] = min(dp[i][g][j], top1_v + cost[i][j]);
               } else if (top2_j != -1 && top2_v != INT32_MAX) {
                 // FIX2: 需要加min
                 dp[i][g][j] = min(dp[i][g][j], top2_v + cost[i][j]);
               }
             }
           }
         } else {
           // 当前房屋已经有颜色
           int minv = INT32_MAX;
           int color = houses[i] - 1;
           for (int g = 2; g <= min(i + 1, target); ++g) {
             for (int j = 0; j < n; ++j) {
               if (j == color) continue;
               // g + 1可能越界
               dp[i][g][color] = min(dp[i][g][color], dp[i - 1][g-1][j]);
             }
           }
           // j == color
           for (int g = 1; g <= target; ++g) {
             dp[i][g][color] = min(dp[i][g][color], dp[i - 1][g][color]);
           }
         }
       }
       // FIX1: 下标要写对
       int ans = *min_element(dp[m - 1][target], dp[m - 1][target + 1]);
       return ans == INT32_MAX ? -1 : ans;
    }
};
#elif SOLUTION == 2

// top-k只要数字, 不需要index
int dp[101][101][21];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      /*
       * 状态:
       *     最小花费: dp[i][g][c]
       *     当前已经涂完下标为i的房子, 下标为i的房子现在的颜色为c, 目前组成的街区数为g
       *     if houses[i] == 0 {
       *         // 需要涂色
       *         dp[i][g][c] = min(dp[i-1][g][j| j=c], dp[i-1][g-1][j | j != c]) + cost[i][j]
       *     } else {
       *         dp[i][g][houses[i]] = min(dp[i - 1][g][houses[i]], dp[i - 1][g-1][c] (c != houses[i]))
       *         others: INT32_MAX
       *     } 
       */
       // init
       // 这里会越界dm[m], 对应FIX3
       fill(dp[0][0], dp[m][0], INT32_MAX);
       if (houses[0] == 0) {
         for (int j = 0; j < n; ++j) {
           dp[0][1][j] = cost[0][j];
         }
       } else {
         dp[0][1][houses[0] - 1] = 0;
       }
       for (int i = 1; i < m; ++i) {
         if (houses[i] == 0) {
           for (int g = 1; g <= min(i, target); ++g) {
             // 和前面同色
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g][j];
               if (v == INT32_MAX) continue;
               dp[i][g][j] = v + cost[i][j]; 
             }
           }
           for (int g = 2; g <= min(i + 1, target); ++g) {
             // 和前面不同色
             // 注意: 不同色时g需要大于等于2
             int top1_v = INT32_MAX, top2_v = INT32_MAX;
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g - 1][j];
               if (v < top1_v) {
                 top2_v = top1_v;
                 top1_v = v;
               } else if (v < top2_v) top2_v = v;
             }
             if (top1_v == INT32_MAX) continue;
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g - 1][j];
               if (v == top1_v) {
                 if (top2_v == INT32_MAX) continue;
                 dp[i][g][j] = min(dp[i][g][j], top2_v + cost[i][j]);
               } else {
                 dp[i][g][j] = min(dp[i][g][j], top1_v + cost[i][j]);
               }
             }
           }
         } else {
           // 当前房屋已经有颜色
           int color = houses[i] - 1;
           for (int g = 1; g <= min(i + 1, target); ++g) {
             int v = dp[i - 1][g][color];  // 按同色初始化, 注意第一个下标
             // 按不同色更新
             for (int j = 0; j < n; ++j) {
               if (j == color) continue;
               v = min(v, dp[i - 1][g - 1][j]);
             }
             dp[i][g][color] = v;
           }
         }
       }
       int ans = *min_element(dp[m - 1][target], dp[m - 1][target + 1]);
       return ans == INT32_MAX ? -1 : ans;
    }
};

#elif SOLUTION == 3

// 合并houses[i] == 0的true和false条件
int dp[101][101][21];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      /*
       * 状态:
       *     最小花费: dp[i][g][c]
       *     当前已经涂完下标为i的房子, 下标为i的房子现在的颜色为c, 目前组成的街区数为g
       *     if houses[i] == 0 {
       *         // 需要涂色
       *         dp[i][g][c] = min(dp[i-1][g][j| j=c], dp[i-1][g-1][j | j != c]) + cost[i][j]
       *     } else {
       *         dp[i][g][houses[i]] = min(dp[i - 1][g][houses[i]], dp[i - 1][g-1][c] (c != houses[i]))
       *         others: INT32_MAX
       *     } 
       */
       // init
       // 这里会越界dm[m], 对应FIX3
       fill(dp[0][0], dp[m][0], INT32_MAX);
       if (houses[0] == 0) {
         for (int j = 0; j < n; ++j) {
           dp[0][1][j] = cost[0][j];
         }
       } else {
         dp[0][1][houses[0] - 1] = 0;
       }
       for (int i = 1; i < m; ++i) {
         // 合并条件, 最后再考虑是否加cost[i][j]
         if (1) {
           const int color = houses[i] - 1;
           for (int g = 1; g <= min(i + 1, target); ++g) {
             // 注意: 不同色时g需要大于等于2
             int top1_v = INT32_MAX, top2_v = INT32_MAX;
             for (int j = 0; j < n; ++j) {
               int v = dp[i - 1][g - 1][j];
               if (v < top1_v) {
                 top2_v = top1_v;
                 top1_v = v;
               } else if (v < top2_v) top2_v = v;
             }

             // 这里不能因为top1_v是INT32_MAX就返回, 因为可能和前面同色且g == 1的情况

             for (int j = 0; j < n; ++j) {
               if (color == -1 || color == j) {
                 // 和前面同色的情况
                 int tmp = dp[i - 1][g][j];
                 // 不同色
                 // v记录的是和上一个同色时的值
                 int v = dp[i - 1][g - 1][j];
                 tmp = min(tmp, v == top1_v ? top2_v : top1_v);
                 if (tmp != INT32_MAX) {
                   if (color == -1) tmp += cost[i][j];
                   dp[i][g][j] = tmp;
                 }
               }
             }
           }
         }
       }
       int ans = *min_element(dp[m - 1][target], dp[m - 1][target + 1]);
       return ans == INT32_MAX ? -1 : ans;
    }
};

#endif

int main() {
  {
    vector<int> houses = {0, 0, 0, 0, 0};
    vector<vector<int> > cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
    cout << Solution().minCost(houses, cost, 5, 2, 3) << endl; 
  }
  {
    vector<int> houses = {0, 2, 1, 2, 0};
    vector<vector<int> > cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
    cout << Solution().minCost(houses, cost, 5, 2, 3) << endl; 
  }
  {
    vector<int> houses = {0, 0, 0, 0, 0};
    vector<vector<int> > cost = {{1, 10}, {10, 1}, {1, 10}, {10, 1}, {1, 10}};
    cout << Solution().minCost(houses, cost, 5, 2, 5) << endl; 
  }
  {
    vector<int> houses = {3, 1, 2, 3};
    vector<vector<int> > cost = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    cout << Solution().minCost(houses, cost, 4, 3, 3) << endl; 
  }
  return 0;
}
