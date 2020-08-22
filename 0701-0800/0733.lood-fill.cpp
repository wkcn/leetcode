class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldc = image[sr][sc];
        if (oldc == newColor) return image;
        queue<pair<int, int> > q;
        image[sr][sc] = newColor;
        q.push({sr, sc});
        const int rows = image.size();
        const int cols = image[0].size();
        auto F = [&](unsigned int r, unsigned int c) {
            if (r >= rows || c >= cols) return;
            if (image[r][c] == oldc) {
                image[r][c] = newColor;
                q.push({r, c});
            }
        };
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            F(r+1, c);
            F(r-1, c);
            F(r, c+1);
            F(r, c-1);
        }
        return image;
    }
};
