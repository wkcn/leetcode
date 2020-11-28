class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        int cnt = 0;
        int i = 0, j;
        while (i < n) {
            ++cnt;
            int left = points[i][0], right = points[i][1];
            for (j = i + 1; j < n; ++j) {
                if (right >= points[j][0]) {
                    right = min(right, points[j][1]);
                } else break;
            }
            i = j;
        }
        return cnt;
    }
};
