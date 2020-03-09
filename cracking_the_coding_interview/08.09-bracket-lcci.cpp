class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string buf;
        gen(0, n, buf, ans);
        return ans;
    }
    void gen(int right, int rest, string &buf, vector<string> &ans) {
        if (right == 0 && rest == 0) {
            ans.push_back(buf);
            return;
        }
        if (right > 0) {
            buf += ')';
            gen(right-1, rest, buf, ans);
            buf.pop_back();
        }
        if (rest > 0) {
            buf += '(';
            gen(right+1, rest-1, buf, ans);
            buf.pop_back();
        }
    }
};
