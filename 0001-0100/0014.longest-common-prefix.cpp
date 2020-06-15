class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 注意strs为空时
        if (strs.empty()) return {};
        int i = 0;
        while (1) {
            if (i >= strs[0].size()) break;
            char c = strs[0][i];
            bool m = true;
            for (string &s : strs) {
                if (i >= s.size() || s[i] != c) {
                    m = false;
                    break;
                }
            }
            if (m) ++i;
            else break;
        }
        return strs[0].substr(0, i);
    }
};
