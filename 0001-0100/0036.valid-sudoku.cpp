class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<int, 9> rows{}, cols{}, grids{};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int p = (r / 3) * 3 + (c / 3);
                int v = board[r][c] - '0';
                int m = 1 << v;
                if ((rows[r] & m) || (cols[c] & m) || (grids[p] & m)) return false;
                rows[r] |= m;
                cols[c] |= m;
                grids[p] |= m;
            }
        }
        return true;
    }
};
