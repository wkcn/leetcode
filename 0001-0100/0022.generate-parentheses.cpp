class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        vector<string> ans;
        const int len = n * 2;
        string buf(len, ' ');
        std::function<void(int, int, int)> F;
        F = [&](int rest, int right, int i) {
            if (i == len) {
                ans.push_back(buf);
                return;
            }
            if (rest > 0) {
                buf[i] = '(';
                F(rest-1, right+1, i+1);
            }
            if (right > 0) {
                buf[i] = ')';
                F(rest, right-1, i+1);
            }
        };
        F(n, 0, 0);
        return ans;
    }
};
