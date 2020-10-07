class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        const int rows = land.size();
        if (rows == 0) return {};
        const int cols = land[0].size();
        if (cols == 0) return {};
        function<int(unsigned int, unsigned int)> F;
        F = [&](unsigned int r, unsigned int c) -> int {
            if (r >= rows || c >= cols) return 0;
            if (land[r][c] != 0) return 0;
            land[r][c] = -1;
            int cnt = 1;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    cnt += F(r + dr, c + dc);
                }
            }
            return cnt;
        };
        vector<int> out;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (land[r][c] == 0) {
                    out.push_back(F(r, c));
                }
            }
        }
        sort(out.begin(), out.end());
        return out;
    }
};
