class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> cnts;
        for (int x : candidates) ++cnts[x];
        vector<pair<int, int> > vs(cnts.begin(), cnts.end()); // sorted
        vector<vector<int> > ans;
        vector<int> buf;
        function<void(int, int)> F = [&](int i, int su) {
            if (su == target) {
                ans.push_back(buf);
                return;
            }
            if (i >= vs.size()) return;
            int new_su = vs[i].first + su;
            if (new_su > target) return;
            F(i + 1, su);
            int old_size = buf.size();
            for (int c = 1; c <= vs[i].second; ++c) {
                su += vs[i].first;
                if (su > target) break;
                buf.push_back(vs[i].first);
                F(i + 1, su);
            }
            buf.resize(old_size);
        };
        F(0, 0);
        return ans;
    }
};
