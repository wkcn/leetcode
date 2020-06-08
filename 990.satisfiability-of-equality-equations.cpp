#include "common.h"
// TODO: 并查集的平衡性
// 路径压缩优化

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        array<array<set<int>, 2>, 26> G;
        for (string &s : equations) {
            int a = s[0] - 'a';
            int b = s[3] - 'a';
            bool ne = s[1] == '!';
            G[a][ne].insert(b);
            G[b][ne].insert(a);
        }
        int num = 0;
        // 注意类型！！
        array<int, 26> vs;
        vs.fill(-1);
        for (int i = 0; i < 26; ++i) {
            if (vs[i] == -1) {
                int cur = num++;
                vs[i] = cur;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int t = q.front(); q.pop();
                    for (const int &u : G[t][0]) {
                        if (vs[u] == -1) {
                            vs[u] = cur;
                            q.push(u);
                        } else {
                            // if (vs[u] != cur) return false;
                        }
                    }
                }

            }
        }
        for (int i = 0; i < 26; ++i) {
            if (vs[i] != -1) {
                for (const int &u : G[i][1]) {
                    if (vs[i] == vs[u]) return false;
                }
            }
        }
        return true;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        array<array<set<int>, 2>, 26> G;
        vector<pair<int, int> > nes;
        unordered_map<int, int> parents;
        for (string &s : equations) {
            int a = s[0] - 'a';
            int b = s[3] - 'a';
            bool ne = s[1] == '!';
            if (ne) {
                nes.push_back({a, b});
            } else {
                int pa = find_parent(parents, a);
                int pb = find_parent(parents, b);
                parents[pb] = pa;
            }
        }
        for (auto &[a, b] : nes) {
            int pa = find_parent(parents, a);
            int pb = find_parent(parents, b);
            if (pa == pb) return false;
        }
        return true;
    }
    int find_parent(unordered_map<int, int> &parents, int t) {
        while (1) {
            auto p = parents.find(t);
            if (p == parents.end()) break;
            if (t == p->second) return t;
            t = p->second;
        }
        return t;
    }
};
#endif

int main() {
  vector<string> eqs;
  INPUT_ARRAY(eqs);
  cout << Solution().equationsPossible(eqs) << endl;
  return 0;
}
