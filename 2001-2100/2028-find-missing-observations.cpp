class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        int rest = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> ans;
        for (int i = n; i > 0; --i) {
            // x + other = rest
            // x = rest - other
            // rest - 6 * (i - 1) <= x <= rest - (i - 1)
            // 1 <= x <= 6
            const int left = max(1, rest - 6 * (i - 1));
            const int right = min(6, rest - (i - 1));
            if (left > right) return {};
            ans.push_back(left);
            rest -= left;
        }
        return ans;
    }
};
