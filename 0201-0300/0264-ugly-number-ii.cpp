class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vs(n); vs[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int v2 = vs[p2] * 2;
            int v3 = vs[p3] * 3;
            int v5 = vs[p5] * 5;
            int v = min({v2, v3, v5});
            vs[i] = v;
            if (v2 == v) ++p2;
            if (v3 == v) ++p3;
            if (v5 == v) ++p5;
        }
        return vs[n - 1];
    }
};
