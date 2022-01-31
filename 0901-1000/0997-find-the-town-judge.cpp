class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n, 0), out(n, 0);
        for (auto &t : trust) {
            ++out[t[0]-1];
            ++in[t[1]-1];
        }
        int found = -1;
        for (int i = 0; i < n; ++i) {
            if (out[i] == 0 && in[i] == n - 1) {
                if (found != -1) return -1;
                found = i + 1;
            }
        }
        return found;
    }
};
