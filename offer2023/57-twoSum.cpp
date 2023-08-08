class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            // search in nums[i + 1:j]
            auto left = nums.begin() + i + 1;
            auto right = nums.begin() + j;
            auto p = lower_bound(left, right, target - nums[i]);
            if (p != right) {
                if (nums[i] + *p == target) return {nums[i], *p};
            }
            // *p 肯定大于target - nums[i]，所以*p也大于target - nums[i - 1]
            j = p - nums.begin();
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 双指针不会丢失解
        // 假如有一个边界在解的边界上，移动的是另一个边界，那么解就不会丢失
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int su = nums[i] + nums[j];
            if (su == target) return {nums[i], nums[j]};
            if (su > target) --j;
            else ++i;
        }
        return {};
    }
};
