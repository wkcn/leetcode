// TODO: 可以实时计算, 不需要unordered_map
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        array<int, 50000> left, right;
        left.fill(-1); right.fill(-1);
        unordered_map<int, int> cnts;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (left[x] == -1) left[x] = i;
            right[x] = i;
            ++cnts[x];
        }
        int deg = 0;
        for (auto &&r : cnts) deg = max(deg, r.second);
        int best = nums.size();
        for (auto &&r : cnts) {
            if (r.second != deg || left[r.first] == -1) continue;
            int len = right[r.first] - left[r.first] + 1;
            best = min(best, len);
        }
        return best;
    }
};
