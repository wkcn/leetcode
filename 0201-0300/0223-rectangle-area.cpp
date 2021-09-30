class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xmin = max(ax1, bx1);
        int ymin = max(ay1, by1);
        int xmax = min(ax2, bx2);
        int ymax = min(ay2, by2);
        return rectArea(ax1, ay1, ax2, ay2) + rectArea(bx1, by1, bx2, by2) - rectArea(xmin, ymin, xmax, ymax);
    }
    int rectArea(int xmin, int ymin, int xmax, int ymax) {
        return max(xmax - xmin, 0) * max(ymax - ymin, 0);
    }
};
