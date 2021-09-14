class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> start{0, 0};
        int td = compute_dis(start, target);
        for (auto &v : ghosts) {
            if (compute_dis(v, target) <= td) {
                return false;
            }
        }
        return true;
    }
    int compute_dis(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
