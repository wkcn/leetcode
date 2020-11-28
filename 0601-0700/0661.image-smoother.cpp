class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int rows = M.size();
        if (rows == 0) return {};
        const int cols = M[0].size();
        if (cols == 0) return {};
        vector<vector<int> > ans(rows, vector<int>(cols));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int su = 0;
                int cnt = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        unsigned int nr = r + dr;
                        unsigned int nc = c + dc;
                        if (nr < rows && nc < cols) {
                            su += M[nr][nc];
                            ++cnt;
                        }
                    }
                }
                ans[r][c] = su / cnt;
            }
        }
        return ans;
    }
};
