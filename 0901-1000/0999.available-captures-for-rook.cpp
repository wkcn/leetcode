class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_r, rook_c;
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                if (board[r][c] == 'R') {
                    rook_r = r;
                    rook_c = c;
                    break;
                }
            }
        }
        int cap = 0;
        auto F = [&](const int offset_r, const int offset_c) {
            int r = rook_r, c = rook_c;
            while (1) {
                r += offset_r; c += offset_c;
                if (r < 0 || c < 0 || r >= 8 || c >= 8) break;
                switch (board[r][c]) {
                    case '.':
                        break;
                    case 'B':
                        return;
                    case 'p':
                        ++cap;
                        return;
                }
            }
        };
        F(0, -1);
        F(0, 1);
        F(-1, 0);
        F(1, 0);
        return cap;
    }
};
