class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
        // (x - x1) * (y2 - y1) = (y - y1) * (x2 - x1)
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            if ((coordinates[i][0] - x1) * dy != (coordinates[i][1] - y1) * dx) return false;
        }
        return true;
    }
};
