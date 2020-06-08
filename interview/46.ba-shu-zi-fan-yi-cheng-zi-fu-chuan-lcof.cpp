class Solution {
public:
    int translateNum(int num) {
        if (num == 0) return 1;
        vector<int> vs;
        while (num > 0) {
            vs.push_back(num % 10);
            num /= 10;
        }
        reverse(vs.begin(), vs.end());
        // [1, 2, 2, 5, 8]
        const int n = vs.size();
        int pre = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            int last = cur;
            if (vs[i - 1] != 0) {
                int u = vs[i - 1] * 10 + vs[i];
                if (u >= 0 && u <= 25) {
                    cur += pre;
                }
            }
            pre = last;
        }
        return cur;
    }
};
