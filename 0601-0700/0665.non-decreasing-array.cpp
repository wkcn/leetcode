class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (++cnt >= 2) return false;
                // 逆序对(a, b), i 在b位置
                // 可以用a替换b, 也可以用b替换a
                if ((i + 1 < n && nums[i - 1] > nums[i + 1]) && (
                    i >= 2 && nums[i - 2] > nums[i]
                )) return false;
            }
        }
        return true;
    }
};
