const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int rows = image.size();
        if (rows == 0) return {};
        const int cols = image[0].size();
        if (cols == 0) return {};
        if (image[sr][sc] == newColor) return image;
        queue<pair<int, int> > q;
        q.push({sr, sc});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                unsigned int nr = p.first + dir[d][0];
                unsigned int nc = p.second + dir[d][1];
                if (nr < rows && nc < cols && image[nr][nc] == color) {
                    q.push({nr, nc});
                    image[nr][nc] = newColor;
                }
            }
        }
        return image;
    }
};
