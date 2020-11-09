class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        int i = 0;
        for (; i < intervals.size(); ++i) {
            auto &v = intervals[i];
            if (newInterval[0] <= v[1] && newInterval[1] >= v[0]) {
                newInterval[0] = min(newInterval[0], v[0]);
                newInterval[1] = max(newInterval[1], v[1]);
            } else {
                if (v[0] <= newInterval[0])
                    res.emplace_back(std::move(v));
                else break;
            }
        }
        res.emplace_back(std::move(newInterval));
        for (; i < intervals.size(); ++i) {
            res.emplace_back(std::move(intervals[i]));
        }
        return res;
    }
};
