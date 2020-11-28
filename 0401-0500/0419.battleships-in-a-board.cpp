class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int countBattleships(vector<vector<char>>& board) {
        // 这个题目不会出现失败样例!
        const int rows = board.size();
        if (rows == 0) return 0;
        const int cols = board[0].size();
        if (cols == 0) return 0;
        int cnt = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'X') {
                    // 只记录尾部
                    if (r + 1 < rows && board[r + 1][c] == 'X') continue;
                    if (c + 1 < cols && board[r][c + 1] == 'X') continue;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
