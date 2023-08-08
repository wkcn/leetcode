class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return {};
        const int n = a.size();
        vector<int> b(n);
        b[0] = 1;
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        int e = 1;
        for (int i = n - 2; i >= 0; --i) {
            e *= a[i + 1];
            b[i] *= e;
        }
        return b;
    }
};
