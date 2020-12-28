class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int len = s.size();
        if (t.size() != len) return false;
        if (len == 0) return true;

        bool used[256]{false};
        int ma[256];
        fill(ma, ma+256, -1);
        for (int i = 0; i < len; ++i) {
            int u = s[i];
            int e = t[i];
            if (ma[u] == -1) {
                if (used[e]) return false;
                used[e] = true;
                ma[u] = e;
            } else {
                if (ma[u] != e) return false;
            }
        }
        return true;
    }
};
