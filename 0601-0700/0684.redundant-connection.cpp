class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> parents(n + 1);
        iota(parents.begin(), parents.end(), 0);
        for (vector<int> &e : edges) {
            int pa = get_parent(parents, e[0]);
            int pb = get_parent(parents, e[1]);
            if (pa == pb) return e;
            parents[pa] = pb;
        }
        return {};
    }
    int get_parent(vector<int> &parents, int i) {
        if (parents[i] == i) return i;
        return parents[i] = get_parent(parents, parents[i]);
    }
};
