// to_string('O')返回的是"79", 因为传入函数to_string(int)
// 其实Check只需要返回bool, 判断第一格与后面的格子
class Solution {
public:
    string tictactoe(vector<string>& board) {
        const int N = board.size();
        string t;
        for (int r = 0; r < N; ++r) {
            t = Check(board, {r, 0}, {0, 1}, N);
            if (!t.empty()) return t;
        }
        for (int c = 0; c < N; ++c) {
            t = Check(board, {0, c}, {1, 0}, N);
            if (!t.empty()) return t;
        }
        t = Check(board, {0, 0}, {1, 1}, N);
        if (!t.empty()) return t;
        t = Check(board, {0, N-1}, {1, -1}, N);
        if (!t.empty()) return t;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c)
                if (board[r][c] == ' ') {
                    return "Pending";
                }
        }
        return "Draw";
    }
    string Check(vector<string> &board, const array<int, 2> &start, const array<int, 2> &vel, int step) {
        int r = start[0], c = start[1];
        const char e = board[r][c];
        if (e == ' ') return {};
        for (int i = 1; i < step; ++i) {
            r += vel[0]; c += vel[1];
            const char t = board[r][c];
            // if (t == ' ') return {};
            if (t != e) return {}; // t == ' '时也会返回
        }
        return string()+e;
    }
};
