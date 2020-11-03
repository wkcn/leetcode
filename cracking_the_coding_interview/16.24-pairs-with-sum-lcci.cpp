// 340 ms
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = int(nums.size()) - 1;
        vector<vector<int> > res;
        while (i < j) {
            int su = nums[i] + nums[j];
            if (su == target) {
                res.push_back({nums[i++], nums[j--]});
            } else if (su < target) ++i;
            else --j;
        }
        return res;
    }
};

// 292 ms
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> cnts;
        vector<vector<int> > res;
        for (int &x : nums) {
            int rest = target - x;
            auto p = cnts.find(rest);
            if (p != cnts.end()) {
                res.push_back({x, rest});
                if (--(p->second) == 0) cnts.erase(p);
            } else {
                ++cnts[x];
            }
        }
        return res;
    }
};
