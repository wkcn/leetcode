class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ma;
        unordered_map<string, char> ma2;
        int i = 0;
        for (char c : pattern) {
            if (i >= s.size()) return false;
            int j = i + 1;
            while (j < s.size() && s[j] != ' ') ++j;
            string w = s.substr(i, j - i);
            auto r = ma.insert({c, {}});
            auto r2 = ma2.insert({w, {}});
            if (r.second) {
                if (!r2.second) return false;
                r.first->second = move(w);
                r2.first->second = c;
            } else {
                if (r.first->second != w) return false;
                if (r2.first->second != c) return false;
            }
            i = j + 1;
        }
        return i >= s.size();
    }
};
