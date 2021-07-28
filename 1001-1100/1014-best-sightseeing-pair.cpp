class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // (values[i] + i) + (values[j] - j)
        int ma = values[0] + 0;
        int ans = values[0] + 0 - (values[1] - 1);
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, ma + (values[i] - i));
            ma = max(ma, values[i] + i);
        }
        return ans;
    }
};
