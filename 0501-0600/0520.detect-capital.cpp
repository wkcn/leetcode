class Solution {
public:
    bool detectCapitalUse(string word) {
        const int n = word.size();
        if (n < 2) return true;
        if (islower(word[1])) {
            for (int i = 2; i < n; ++i) {
                if (isupper(word[i])) return false;
            }
        } else {
            if (islower(word[0])) return false;
            for (int i = 2; i < n; ++i) {
                if (islower(word[i])) return false;
            }
        }
        return true;
    }
};
