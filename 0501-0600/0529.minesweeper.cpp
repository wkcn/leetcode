class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int rows = board.size();
        const int cols = board[0].size();
        // M, E, B, 1 to 8, X
        char &c = board[click[0]][click[1]];
        if (c == 'M') {
            c = 'X';
        } else if (c == 'E') {
            queue<pair<int, int> > q;
            c = '#';
            q.push({click[0], click[1]});
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                int num = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        unsigned int nr = dr + r;
                        unsigned int nc = dc + c;
                        if (nr < rows && nc < cols) {
                            if (board[nr][nc] == 'M') ++num;
                        }
                    }
                }
                board[r][c] = num == 0 ? 'B' : (num + '0');
                if (num == 0) {
                    for (int dr = -1; dr <= 1; ++dr) {
                        for (int dc = -1; dc <= 1; ++dc) {
                            if (dr == 0 && dc == 0) continue;
                            unsigned int nr = dr + r;
                            unsigned int nc = dc + c;
                            if (nr < rows && nc < cols) {
                                if (board[nr][nc] == 'E') {
                                    board[nr][nc] = '#';
                                    q.push({nr, nc});
                                }
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};
