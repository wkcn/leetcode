class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 要么自己开始, 要么和前面最大的连续数列合并
        // 注意样例: nums = {-1}, 只有一个数字而且还是负数的情况
        int pre = nums[0];
        int best = pre;
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            pre = max(pre + x, x);
            best = max(pre, best);
        }
        return best;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums, 0, nums.size());
    }
    int maxSub(vector<int> &nums, int start, int end) {
        if (end - start == 1) return nums[start];
        int mid = start + ((end - start) >> 1);
        int left_max = maxSub(nums, start, mid);
        int right_max = maxSub(nums, mid, end);
        int su = 0; int left = 0;
        for (int i = mid - 1; i >= start; --i) {
            su += nums[i];
            left = max(left, su);
        }
        su = 0; int right = 0;
        for (int i = mid + 1; i < end; ++i) {
            su += nums[i];
            right = max(right, su);
        }
        int mid_max = left + nums[mid] + right;
        return max({left_max, mid_max, right_max});
    }
};
