// 还可以用分组, 异或, 求和
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        // N = nums.size() + 2
        const int n = nums.size();
        bool p1 = false, p2 = false;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] <= n) {
                    swap(nums[nums[i] - 1], nums[i]);
                } else {
                    if (nums[i] == n + 1) p1 = true;
                    else p2 = true;
                    break;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) res.push_back(i + 1);
        }
        if (!p1) res.push_back(n + 1);
        if (!p2) res.push_back(n + 2);
        return res;
    }
};
