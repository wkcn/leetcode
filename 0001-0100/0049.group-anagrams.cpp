class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > se;
        for (string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            se[t].push_back(s);
        }
        vector<vector<string> > res;
        for (auto &r : se) {
            res.emplace_back(move(r.second));
        }
        return res;
    }
};
