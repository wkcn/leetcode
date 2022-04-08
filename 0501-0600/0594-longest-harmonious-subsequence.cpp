class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int x : nums) ++cnts[x];
        int ans = 0;
        for (auto [k, v] : cnts) {
            auto p = cnts.find(k + 1);
            if (p != cnts.end()) {
                int e = v + p->second;
                ans = max(ans, e);
            }
        }
        return ans;
    }
};
