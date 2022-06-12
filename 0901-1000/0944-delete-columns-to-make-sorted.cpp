class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int N = strs.size();
        const int M = strs[0].size();
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            bool right = true;
            for (int j = 1; j < N; ++j) {
                if (strs[j-1][i] > strs[j][i]) {
                    right = false;
                    break;
                }
            }
            if (!right) ++cnt;
        }
        return cnt;
    }
};
