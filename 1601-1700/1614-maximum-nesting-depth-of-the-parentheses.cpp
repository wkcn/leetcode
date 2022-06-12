class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int left = 0;
        for (char c : s) {
            switch (c) {
                case '(':
                    ans = max(ans, ++left);
                    break;
                case ')':
                    --left;
                    break;
            }
        }
        return ans;
    }
};
