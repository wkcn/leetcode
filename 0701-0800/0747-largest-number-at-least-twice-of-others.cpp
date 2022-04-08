class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 0;
        int second = ans;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[ans]) {
                second = nums[ans];
                ans = i;
            } else if (nums[i] > second) second = nums[i];
        }
        if (nums[ans] >= second * 2) return ans;
        return -1;
    }
};
