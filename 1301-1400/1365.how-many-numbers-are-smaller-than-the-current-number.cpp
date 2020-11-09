class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // O(nlogn)
        if (nums.empty()) return {};
        vector<int> data(nums.begin(), nums.end());
        sort(data.begin(), data.end());
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = lower_bound(data.begin(), data.end(), nums[i]) - data.begin();
        }
        return res;
    }
};
