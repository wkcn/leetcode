class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> inds(nums.size());
        iota(inds.begin(), inds.end(), 0);
        sort(inds.begin(), inds.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int v = nums[inds[i]] + nums[inds[j]];
            if (v == target) return {inds[i], inds[j]};
            else if (v < target) ++i;
            else --j;

        }
        return {};
    }
};
