class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int> > ans;
        int i = 0, j;
        while (i < s.size()) {
            for (j = i + 1; j < s.size() && s[i] == s[j]; ++j);
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
