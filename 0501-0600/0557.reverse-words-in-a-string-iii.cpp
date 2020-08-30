class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < s.size()) {
            while (i < s.size() && s[i] == ' ') ++i;
            j = i + 1;
            while (j < s.size() && s[j] != ' ') ++j;
            // [i, j)
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};
