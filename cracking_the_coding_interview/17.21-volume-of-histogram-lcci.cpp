class Solution {
public:
    int trap(vector<int>& height) {
        // 每一格子的水量, 取决其左右最高值
        const int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int v = 0;
        for (int i = 0; i < n; ++i) {
            v = max(v, height[i]);
            left[i] = v;
        }
        v = 0;
        for (int i = n - 1; i >= 0; --i) {
            v = max(v, height[i]);
            right[i] = v;
        }
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += min(left[i], right[i]) - height[i];
        }
        return s;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int left = 0, right = height.size() - 1;
        int left_most = height.front(), right_most = height.back();
        int ans = 0;
        while (left < right) {
            if (left_most < right_most) {
                ans += left_most - height[left];
                left_most = max(left_most, height[++left]);
            } else {
                ans += right_most - height[right];
                right_most = max(right_most, height[--right]);
            }
        }
        return ans;
    }
};
