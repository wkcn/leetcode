class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        const int h = min((int)nums.size(), k);
        for (int i = 0; i < h; ++i) {
            if (++cnts[nums[i]] == 2) return true;
        }
        for (int i = h; i < nums.size(); ++i) {
            if (++cnts[nums[i]] == 2) return true;
            --cnts[nums[i - k]];
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> cnts;
        const int h = min((int)nums.size(), k);
        for (int i = 0; i < h; ++i) {
            if (!cnts.insert(nums[i]).second) return true;
        }
        for (int i = h; i < nums.size(); ++i) {
            if (!cnts.insert(nums[i]).second) return true;
            cnts.erase(nums[i - k]);
        }
        return false;
    }
};
