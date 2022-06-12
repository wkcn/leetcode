class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> se;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k + 1) {
                se.erase(nums[i - k - 1]);
            }
            if (!se.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};
