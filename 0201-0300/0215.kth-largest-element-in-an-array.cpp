class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int i = left, j = right;
            int pv = nums[i];
            while (i < j) {
                while (i < j && nums[j] >= pv) --j;
                nums[i] = nums[j];
                while (i < j && nums[i] <= pv) ++i;
                nums[j] = nums[i];
            }
            nums[i] = pv;
            // i == j
            int m = right - i + 1;
            if (m == k) return pv;
            if (m > k) {
                left = i + 1;
            } else {
                right = i - 1;
                k -= m;
            }
        }
        // 注意这里
        return nums[left];
    }
};
