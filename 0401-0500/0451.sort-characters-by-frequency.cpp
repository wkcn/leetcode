class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) ++cnts[c];
        vector<pair<int, int> > ps(cnts.begin(), cnts.end());
        sort(ps.begin(), ps.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        string ans;
        for (auto &p : ps) {
            ans += string(p.second, p.first);
        }
        return ans;
    }
};

// bucket
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) ++cnts[c];
        string ss[s.size() + 1];
        for (auto &p : cnts) {
            ss[p.second] += string(p.second, p.first);
        }
        string ans;
        for (int i = s.size(); i >= 1; --i) {
            ans += ss[i];
        }
        return ans;
    }
};
