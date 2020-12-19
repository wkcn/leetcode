class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> ma;
        ma[0] = -1;
        int cnt = 0;
        int best = 0;
        int start;
        for (int i = 0; i < array.size(); ++i) {
            if (isdigit(array[i][0])) {
                ++cnt;
            } else --cnt;
            auto p = ma.insert({cnt, i});
            if (!p.second) {
                int len = i - p.first->second;
                if (len > best) {
                    best = len;
                    start = p.first->second + 1;
                }
            }
        }
        if (best == 0) return {};
        vector<string> res(array.begin() + start, array.begin() + start + best);
        return res;
    }
};
