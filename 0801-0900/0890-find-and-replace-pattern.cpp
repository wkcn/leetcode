class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string &word : words) {
            if (Matched(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool Matched(string &a, string &p) {
        unordered_map<char, char> ma, ia;
        for (int i = 0; i < a.size(); ++i) {
            char c = a[i];
            char d = p[i];
            auto r = ma.insert({d, c});
            if (!r.second) {
                if (r.first->second != c) return false;
            }
            auto w = ia.insert({c, d});
            if (!w.second) {
                if (w.first->second != d) return false;
            }
        }
        return true;
    }
};
