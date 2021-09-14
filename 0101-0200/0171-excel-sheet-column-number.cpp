class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            ans = ans * 26 - 'A' + columnTitle[i] + 1;
        }
        return ans;
    }
};
