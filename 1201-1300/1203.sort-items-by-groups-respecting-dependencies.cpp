#include "common.h"

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int g = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = g++;
        }
        vector<vector<int> > LG(g), SG(n);
        vector<int> LD(g, 0), SD(n, 0);  // 度数
        vector<vector<int> > ids(g); // ids[group_id] = {xxx}
        for (int i = 0; i < n; ++i) {
            int g = group[i];
            ids[g].push_back(i);
            for (int t: beforeItems[i]) {
                // [重要！！！！]需要分组，同一组或者不同组
                if (group[t] == group[i]) {
                  SG[t].push_back(i);
                  ++SD[i];
                } else {
                  LG[group[t]].push_back(group[i]);
                  ++LD[group[i]];
                }
            }
        }
        vector<int> all_ids(g);
        iota(all_ids.begin(), all_ids.end(), 0);
        vector<int> gorder = Topo(LG, LD, all_ids);
        if (gorder.empty()) return {};

        vector<int> ans;
        for (int e : gorder) {
            vector<int> iorder = Topo(SG, SD, ids[e]);
            if (iorder.size() != ids[e].size()) return {};
            ans.insert(ans.end(), iorder.begin(), iorder.end());
        }
        return ans;
    }
    vector<int> Topo(vector<vector<int> > &G, vector<int> &D, vector<int> &ids) {
        vector<int> out;
        queue<int> q;
        for (int i : ids) if (D[i] == 0) {
            out.push_back(i);
            q.push(i);
        }
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int t : G[r]) {
                if (--D[t] == 0) {
                    out.push_back(t);
                    q.push(t);
                }
            }
        }
        if (out.size() != ids.size()) return {};
        return out;
    }
};

int main() {
  int n = 8, m = 2;
  vector<int> group = {-1,-1,1,0,0,1,0,-1};
  vector<vector<int> > beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
  PRINT_ARRAY(Solution().sortItems(n, m, group, beforeItems));
  return 0;
}
