class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            char last = s[0];
            int cnt = 1;
            string t;
            for (int j = 1; j < s.size(); ++j) {
                if (s[j] == last) {
                    ++cnt;
                } else {
                    t += to_string(cnt); t += last;
                    last = s[j];
                    cnt = 1;
                }
            }
            t += to_string(cnt); t += last;
            s = move(t);
        }
        return s;
    }
};
