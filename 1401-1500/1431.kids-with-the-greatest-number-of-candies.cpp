class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        if (candies.empty()) return {};
        int ma = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for (int &x: candies) {
            ans.push_back(x + extraCandies >= ma);
        }
        return ans;
    }
};
