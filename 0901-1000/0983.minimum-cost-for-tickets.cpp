// TODO: 理解清楚
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        array<int, 366> dp;
        dp[0] = 0;
        int di = 0;
        for (int i = 1; i <= 366 && di < days.size(); ++i) {
            if (i == days[di]) {
                dp[i] = min({
                    dp[max(0, i-1)] + costs[0],
                    dp[max(0, i-7)] + costs[1],
                    dp[max(0, i-30)] + costs[2],
                });
                ++di;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[days.back()];
    }
};
