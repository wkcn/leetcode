class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        if (nums.size() < k)
            return accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
        double su = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double max_su = su;
        for (int i = k; i < nums.size(); ++i) {
            su = su + nums[i] - nums[i - k];
            max_su = max(max_su, su);
        }
        return max_su / k;
    }
};
