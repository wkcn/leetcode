class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        const int size = height.size();
        vector<int> left(size), right(size);
        // left 从小到大
        // right 从大到小
        left[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left[i] = max(left[i-1], height[i]);
        }
        right.back() = height.back();
        for (int i = size-2; i >= 0; --i) {
            right[i] = max(right[i+1], height[i]);
        }
        // input: 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1
        //  left: 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3
        // right: 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1
        int ans = 0;
        for (int i = 1; i < size-1; ++i) {
            ans += max(min(left[i], right[i]) - height[i], 0);
        }
        return ans;
    }
};
