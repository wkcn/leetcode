class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> se;
        for (int x : nums) {
            if (!se.insert(x).second) return true;
        }
        return false;
    }
};
