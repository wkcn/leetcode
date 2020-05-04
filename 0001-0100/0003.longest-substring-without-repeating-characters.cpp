class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0; // [i, j)
        array<bool, 256> counts{0};
        const int size = s.size();
        int best_len = 0;
        while (j < size) {
            char &c = s[j++];
            if (counts[c]) {
                while (i < j) {
                    char &u = s[i++];
                    counts[u] = false;
                    if (u == c) break;
                }
            }
            counts[c] = true;
            int len = j - i;
            if (len > best_len) {
                best_len = len;
            }
        }
        return best_len;
    }
};
