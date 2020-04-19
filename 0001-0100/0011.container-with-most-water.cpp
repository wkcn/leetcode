class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 1) return 0;
        int lo = 0, hi = height.size() - 1;
        int best = 0;
        while (lo < hi) {
            int area = min(height[lo], height[hi]) * (hi - lo);
            if (area > best) best = area;
            if (height[lo] < height[hi]) ++lo;
            else --hi;
        }
        return best;
    }
};
