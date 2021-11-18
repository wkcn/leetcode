class Solution {
public:
    string toHex(int num) {
        const string ds = "0123456789abcdef";
        if (num == 0) return "0";
        bool first = true;
        string ans;
        for (int i = 7; i >= 0; --i) {
            int v = (num >> (i * 4)) & 0xf;
            if (!first || v > 0) {
                ans += ds[v];
                first = false;
            }
        }
        return ans;
    }
};
