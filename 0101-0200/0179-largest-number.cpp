class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for (int x : nums) vs.push_back(to_string(x));
        sort(vs.begin(), vs.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        string ans = accumulate(vs.begin(), vs.end(), string(""));
        // 注意[0, 0]
        if (ans[0] == '0') return "0";
        return ans;
    }
};
