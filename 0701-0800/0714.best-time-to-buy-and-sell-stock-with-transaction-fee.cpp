class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int w = -prices[0] - fee, o = 0; // 有股票，无股票
        for (int x : prices) {
            w = max(w, o - fee - x);
            o = max(o, w + x);
        }
        return o;
    }
};
