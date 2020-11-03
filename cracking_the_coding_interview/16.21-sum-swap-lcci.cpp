class Solution {
using LL = long long;
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        LL s1 = accumulate(array1.begin(), array1.end(), (LL)0);
        LL s2 = accumulate(array2.begin(), array2.end(), (LL)0);
        LL diff = s1 - s2;
        if (diff & 1) return {};
        unordered_set<LL> se(array1.begin(), array1.end());
        LL half = diff / 2;
        for (int x : array2) {
            LL y = x + half;
            if (se.count(y)) return {(int)y, (int)x};
        }
        return {};
    }
};
