// TODO: 题解里有更简单的方式
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};
        // 首先把同样的字母转为区间表示, 问题变成了区间问题
        // 用贪心的方法解决
        int start[26], end[26];
        memset(start, -1, sizeof(start));
        memset(end, -1, sizeof(end));
        // [start, end]
        for (int i = 0; i < S.size(); ++i) {
            int v = S[i] - 'a';
            if (start[v] == -1) start[v] = i;
            end[v] = i;
        }
        vector<pair<int, int> > ps;
        for (int i = 0; i < 26; ++i) {
            if (start[i] != -1) {
                ps.push_back({start[i], end[i]});
            }
        }
        // 变成合并区间的问题
        sort(ps.begin(), ps.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> res;
        pair<int, int> cur = ps[0];
        for (int i = 1; i < ps.size(); ++i) {
            if (cur.second > ps[i].first) {
                // 合并
                if (cur.second < ps[i].second) cur.second = ps[i].second;
            } else {
                res.push_back(cur.second - cur.first + 1);
                cur = ps[i];
            }
        }
        res.push_back(cur.second - cur.first + 1);
        return res;
    }
};
