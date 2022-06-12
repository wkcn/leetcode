class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> ma;
        for (int i = 0; i < 26; ++i) ma[order[i] - 'a'] = i;
        for (int i = 1; i < words.size(); ++i) {
            if (!le(words[i-1], words[i], ma)) return false;
        }
        return true;
    }
    bool le(string &a, string &b, array<int, 26> &ma) {
        int min_len = min(a.size(), b.size());
        for (int i = 0; i < min_len; ++i) {
            int av = ma[a[i] - 'a'];
            int bv = ma[b[i] - 'a'];
            if (av < bv) return true;
            if (av > bv) return false;
        }
        return a.size() <= b.size();
    }
};
