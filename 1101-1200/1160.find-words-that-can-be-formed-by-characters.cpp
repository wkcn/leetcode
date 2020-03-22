class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<int, 26> cnts{0};
        for (char &c : chars) ++cnts[c - 'a'];
        int ans = 0;
        for (string &s : words) {
            bool fail = false;
            for (char &c : s) {
                if (--cnts[c - 'a'] < 0) fail = true;
            }
            for (char &c : s) ++cnts[c - 'a'];
            if (!fail) ans += s.size();
        }
        return ans;
    }
};
