class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            ma[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto &vs = ma[target];
        return vs[rand() % vs.size()];
    }
private:
    unordered_map<int, vector<int>> ma;
};
