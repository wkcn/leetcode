#include "common.h"


struct DNode {
    DNode *nodes[26]{nullptr};
    int is_leaf = -1;
    ~DNode () {
        for (DNode *r : nodes) delete r;
    }
};

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        if (smalls.empty()) return {};
        DNode root;
        for (int u = 0; u < smalls.size(); ++u) {
            string &s = smalls[u];
            DNode *r = &root;
            for (int i = (int)s.size() - 1; i >= 0; --i) {
                DNode *& t = r->nodes[s[i] - 'a'];
                if (!t) t = new DNode();
                r = t;
            }
            r->is_leaf = u;
        }
        vector<vector<int> > res(smalls.size());
        for (int i = (int)big.size() - 1; i >= 0; --i) {
            DNode *r = &root;
            for (int p = i; p >= 0; --p) {
                DNode *t = r->nodes[big[p] - 'a'];
                if (!t) break;
                if (t->is_leaf != -1) {
                    res[t->is_leaf].push_back(p);
                }
                r = t;
            }
        }
        for (auto &v : res) reverse(v.begin(), v.end());
        return res;
    }
};

int main() {
  string big; vector<string> smalls;
  cin >> big; INPUT_ARRAY(smalls);
  for (auto &v : Solution().multiSearch(big, smalls)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
