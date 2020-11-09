class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> se;
        for (int x : nums1) se.insert(x);
        vector<int> ans;
        for (int x : nums2) {
            auto p = se.find(x);
            if (p != se.end()) {
                ans.push_back(x);
                se.erase(p);
            }
        }
        return ans;
    }
};
