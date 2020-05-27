class Solution {
public:
    int findTheLongestSubstring(string s) {
        const int len = s.size();
        if (len == 0) return 0;
        array<int, 5> flags;
        flags.fill(0);
        map<array<int, 5>, int> ma;
        ma[array<int,5>{0, 0, 0, 0, 0}] = -1;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int id = get_id(s[i]);
            if (id != -1) {
                flags[id] ^= 1;
            }
            auto p = ma.find(flags);
            if (p != ma.end()) {
                ans = max(ans, i - (p->second));
            } else {
                ma[flags] = i;
            }
        }
        return ans;
    }
    inline int get_id(char c) {
        switch (c) {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
        }
        return -1;
    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {
        const int len = s.size();
        if (len == 0) return 0;
        int flags = 0;
        vector<int> ma(1<<5, -1);
        ma[0] = 0;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int id = get_id(s[i]);
            if (id != -1) {
                flags ^= 1 << id;
            }
            if (~ma[flags]) {
                ans = max(ans, i - ma[flags] + 1);
            } else {
                ma[flags] = i + 1;
            }
        }
        return ans;
    }
    inline int get_id(char c) {
        switch (c) {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
        }
        return -1;
    }
};
