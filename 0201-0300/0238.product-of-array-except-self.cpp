// 先用朴素的方法，然后再看看有没有优化的方法
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int R = 1;
        for (int i = n-1; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }
        return ans;
    }
};
