class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // 三个状态，买入，卖出，冻结
        int s1 = -prices[0], s2 = 0, s3 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int p = prices[i];
            int os1 = s1, os2 = s2, os3 = s3;
            s1 = max(os1, os3 - p);
            s2 = os1 + p;
            s3 = max(os3, os2);
        }
        return max({s2, s3});
    }
};
