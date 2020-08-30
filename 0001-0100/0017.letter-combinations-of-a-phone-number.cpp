const string KEYS[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out(1);
        for (char c : digits) {
            const string &keys = KEYS[c - '0'];
            if (keys.empty()) continue;
            vector<string> buf;
            for (string &s : out) {
                for (char u: keys) {
                    buf.emplace_back(s + u);
                }
            }
            out = std::move(buf);
        }
        // 注意无字母时!
        if (out.size() == 1 && out[0].size() == 0) return {};
        return out;
    }
};
