// TODO: 其他更优的方法, 如KMP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int len = s.size();
        for (int l = 1; l < len; ++l) {
            if (len % l) continue;
            int j = l;
            bool fail = false;
            while (j < len) {
                int i = 0;
                while (i < l) {
                    if (s[i] != s[j]) fail = true;
                    ++i;
                    ++j;
                }
            }
            if (!fail) return true;
        }
        return false;
    }
};
