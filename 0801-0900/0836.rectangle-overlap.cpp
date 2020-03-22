class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int minx = max(rec1[0], rec2[0]);
        int miny = max(rec1[1], rec2[1]);
        int maxx = min(rec1[2], rec2[2]);
        int maxy = min(rec1[3], rec2[3]);
        return minx < maxx && miny < maxy;
    }
};
