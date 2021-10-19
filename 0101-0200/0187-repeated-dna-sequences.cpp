class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        unordered_map<int, int> ma;
        int v = 0;
        for (int i = 0; i < 10; ++i) {
            v = v * 4 + DNANum(s[i]);
        }
        ma[v] = 0;
        set<int> es;
        vector<string> ans;
        for (int i = 10; i < s.size(); ++i) {
            int t = DNANum(s[i]);
            v = ((v & 0x3FFFF) << 2) | t;
            auto p = ma.insert({v, i - 9});
            if (!p.second) es.insert(p.first->second);
        }
        for (int i : es) {
            ans.emplace_back(s.substr(i, 10));
        }
        return ans;
    }
    int DNANum(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
};
