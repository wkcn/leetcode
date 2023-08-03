class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ma;
        int ans = 0;
        int i = -1, j = 0;
        while (j < s.size()) {
            char c = s[j];
            auto p = ma.insert({c, j});
            if (!p.second) {
                i = max(i, p.first->second);  // 要取最大
                p.first->second = j;
            }
            ans = max(ans, j - i);
            ++j;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int ans = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && !se.count(s[j])) {
                se.insert(s[j++]);
                ans = max(ans, j - i);
            }
            se.erase(s[i++]);
        }
        return ans;
    }
};
