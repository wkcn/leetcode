// 可以不用hash, 直接按222333444这样查表
const array<string, 10> keys = {
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

map<char, char> MAP; // 'a' -> '2'

class PRE {
public:
    PRE() {
        for (int i = 0; i < 10; ++i) {
            for (const char &c : keys[i]) {
                MAP[c] = i + '0';
            }
        }
    }
};

static PRE pre;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ans;
        const int len = num.size();
        for (const string &s : words) {
            if (s.size() != len) continue;
            bool fail = false;
            for (int i = 0; i < len; ++i) {
                if (MAP[s[i]] != num[i]) {
                    fail = true;
                    break;
                }
            }
            if (!fail) ans.emplace_back(std::move(s));
        }
        return ans;
    }
};
