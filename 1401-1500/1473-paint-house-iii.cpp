#include "common.h"

// dp[i][j][k]: 第i间房子填颜色j时, target为k的最低消费
int dp[101][21][101];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      /*
        if houses[i] == 0 {
          dp[i][j][k] = cost[i][j] + min(min(dp[i - 1][u][k-1], u!=j), dp[i - 1][j][k])
        } else {
          if j = houses[i]
            dp[i][j][k] = min(min(dp[i - 1][u][k-1], u!=j), dp[i - 1][j][k])
          if j != houses[i]
            dp[i][j][k] = INT32_MAX
        }
       */
       for (int j = 0; j < n; ++j) {
         for (int k = 1; k <= target; ++k) {
           dp[0][j][k] = INT32_MAX;
         }
       }
       if (houses[0] == 0) {
         for (int j = 0; j < n; ++j) {
           dp[0][j][1] = cost[0][j];
         }
       } else {
         dp[0][houses[0] - 1][1] = 0;
       }
       for (int i = 1; i < m; ++i) {
         for (int k = 1; k <= target; ++k) {
           // compute dp[i - 1][u][k - 1]
           int min1 = INT32_MAX, min2 = INT32_MAX;
           if (k > 1) {
             for (int u = 0; u < n; ++u) {
               int v = dp[i - 1][u][k - 1];
               if (v <= min1) {
                 min2 = min1; min1 = v;
               } else if (v < min2) min2 = v;
             }
           }
           for (int j = 0; j < n; ++j) {
             if (houses[i] == 0 || j + 1 == houses[i]) {
               int mi = dp[i - 1][j][k];
               if (k > 1) {
                 // 与前面的房子不同颜色
                 int v = dp[i - 1][j][k - 1];
                 mi = min(mi, min1 == v ? min2 : min1);
               }
               if (houses[i] == 0 && mi != INT32_MAX) {
                 mi += cost[i][j];
               }
               dp[i][j][k] = mi;
             } else {
               // j + 1 != houses[i]
               dp[i][j][k] = INT32_MAX;
             }
           }
         }
       }
       int ans = INT32_MAX;
       for (int j = 0; j < n; ++j) {
         ans = min(ans, dp[m - 1][j][target]);
       }
       return ans == INT32_MAX ? -1 : ans;
    }
};

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
}
