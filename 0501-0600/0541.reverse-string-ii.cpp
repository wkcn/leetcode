class Solution {
public:
    string reverseStr(string s, int k) {
        const int n = s.size();
        int start = 0;
        while (start < n) {
            int end = min(n, start + k);
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            start += 2 * k;
        }
        return s;
    }
};
