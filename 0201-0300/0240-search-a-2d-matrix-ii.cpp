struct MRect {
    int minr, minc;
    int maxr, maxc;
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int R = matrix.size(), C = matrix[0].size();
        stack<MRect> st; st.push({0, 0, R, C});
        auto my_push = [&](MRect e) {
            if (e.minr >= e.maxr || e.minc >= e.maxc) return;
            st.push(e);
        };
        while (!st.empty()) {
            MRect e = st.top(); st.pop();
            int r = (e.minr + e.maxr) / 2;
            int c = (e.minc + e.maxc) / 2;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) {
                my_push({e.minr, c + 1, r + 1, e.maxc});
                my_push({r + 1, e.minc, e.maxr, c + 1});
                my_push({r + 1, c + 1, e.maxr, e.maxc});
            } else {
                my_push({e.minr, c, r, e.maxc});
                my_push({r, e.minc, e.maxr, c});
                my_push({e.minr, e.minc, r, c});
            }
        }
        return false;
    }
};
