class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [a, b]: b -> a
        vector<vector<int> > G(numCourses);
        vector<int> idg(numCourses, 0);
        for (auto &p : prerequisites) {
            G[p[1]].push_back(p[0]);
            ++idg[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (idg[i] == 0) q.push(i);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int u: G[t]) {
                if (--idg[u] == 0) q.push(u);
            }
        }
        for (int i = 0; i < numCourses; ++i) if (idg[i] > 0) return false;
        return true;
    }
};
