// TODO: 反证法证明，统计峰和谷
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        // 注意，这里是子序列，不是连续序列
        int up = 1, down = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                up = max(up, down + 1);
            } else if (nums[i - 1] > nums[i]) {
                down = max(down, up + 1);
            }
        }
        return max(up, down);
    }
};
