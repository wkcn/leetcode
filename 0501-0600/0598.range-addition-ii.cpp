class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m, min_n = n;
        for (auto &p : ops) {
            min_m = min(min_m, p[0]);
            min_n = min(min_n, p[1]);
        }
        return min_m * min_n;
    }
};
