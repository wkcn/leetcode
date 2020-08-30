class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        const int N = rooms.size();
        vector<bool> vis(N, false); vis[0] = true;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int u : rooms[t]) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
        for (int i = 0; i < N; ++i) if (!vis[i]) return false;
        return true;
    }
};
