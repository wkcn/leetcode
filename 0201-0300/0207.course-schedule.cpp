// TODO: DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > G(numCourses);
        vector<int> inD(numCourses, 0);
        for (vector<int> &p : prerequisites) {
            G[p[1]].push_back(p[0]);
            ++inD[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inD[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int t : G[r]) {
                if (--inD[t] == 0) q.push(t);
            }
        }
        for (int x : inD) if (x > 0) return false;
        return true;
    }
};
