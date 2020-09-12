class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > out;
        vector<int> buf;
        function<void(int i, int rest)> F;
        F = [&](int i, int rest) {
            if (rest == 0) {
                out.push_back(buf);
                return;
            }
            if (i >= candidates.size()) return;
            const int v = candidates[i];
            if (rest < v) return;
            F(i + 1, rest);
            int old_size = buf.size();
            for (int u = rest - v; u >= 0; u -= v) {
                buf.push_back(v);
                F(i + 1, u);
            }
            buf.resize(old_size);
        };
        F(0, target);
        return out;
    }
};
