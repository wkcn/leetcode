class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        const int R = nums.size();
        if (R == 0) return nums;
        const int C = nums[0].size();
        if (C == 0) return nums;
        if (R * C != r * c) return nums;
        vector<vector<int> > target(r, vector<int>(c));
        for (int i = 0; i < R * C; ++i) {
            target[i / c][i % c] = nums[i / C][i % C];
        }
        return target;
    }
};
