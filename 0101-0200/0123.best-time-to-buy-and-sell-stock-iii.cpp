class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit(2, prices);
    }
    int maxProfit(int k, vector<int>& prices) {
      if (prices.size() < 2) return 0;
      // dp[当前天数][rest_k][是否持有股票]
      // dp[d + 1][i][1] = max(dp[d][i][1], dp[d][i+1][0] - prices[d])
      // dp[d + 1][i][0] = max(dp[d][i][0], dp[d][i][1] + prices[d])
      const int len = prices.size();
      k = min(k, len / 2);  // 交易次数不会超过len / 2次
      int dp[len + 1][k + 1][2];
      for (int i = 0; i <= k; ++i) {
        dp[0][i][0] = 0;
        // 注意初始化，不能用-prices[0]作为初值, 因为这样会导致多了一次交易机会
        dp[0][i][1] = INT32_MIN;
      }
      for (int d = 0; d < len; ++d) {
        for (int i = 0; i <= k; ++i) {
          if (i < k)
            dp[d + 1][i][1] = max(dp[d][i][1], dp[d][i+1][0] - prices[d]);
          else
            dp[d + 1][i][1] = dp[d][i][1];
          
          dp[d + 1][i][0] = max(dp[d][i][0], dp[d][i][1] + prices[d]);
        }
      }
      int ans = 0;
      for (int i = 0; i < k; ++i) {
        ans = max(ans, dp[len][i][0]);
      }
      return ans;
    }
};
