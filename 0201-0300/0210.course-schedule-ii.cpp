class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return {};
        vector<int> in_degree(numCourses, 0);
        vector<vector<int> > G(numCourses);
        for (vector<int> &v : prerequisites) {
            // v[1] -> v[0]
            ++in_degree[v[0]];
            G[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < in_degree.size(); ++i) {
            if (in_degree[i] == 0) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);
            for (int &t : G[u]) {
                if (--in_degree[t] == 0) q.push(t);
            }
        }
        return result.size() == numCourses ? result : vector<int>{};
    }
};
