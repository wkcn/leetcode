#include "common.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // email 是节点
        unordered_map<string, string> parents;
        for (int i = 0; i < accounts.size(); ++i) {
            auto &vs = accounts[i];
            if (vs.size() >= 3) {
                string pa = GetParent(parents, vs[1]);
                for (int j = 2; j < vs.size(); ++j) {
                    string pb = GetParent(parents, vs[j]);
                    parents[pb] = pa;
                }
            }
        }
        // 给每个帐号一个独立的ID, 同一个人的ID一样
        vector<int> ids(accounts.size());
        unordered_map<string, int> m2i;
        int id = 0;
        for (int i = 0; i < accounts.size(); ++i) {
            auto &vs = accounts[i];
            if (vs.size() > 1) {
                string pa = GetParent(parents, vs[1]);
                auto p = m2i.insert({pa, id});
                if (p.second) {
                    ++id;
                }
                ids[i] = p.first->second;
            } else {
                // 没有邮箱
                ids[i] = id++;
            }
        }
        // 根据ids得到结果
        vector<set<string> > res(id);  // 实际的人数
        for (int i = 0; i < accounts.size(); ++i) {
            auto &vs = accounts[i];
            if (vs.size() < 2) continue;
            int tid = ids[i];
            for (int j = 1; j < vs.size(); ++j) {
                res[tid].insert(vs[j]);
            }
        }

        vector<vector<string> > ans(id);
        for (int i = 0; i < accounts.size(); ++i) {
            auto &vs = accounts[i];
            int tid = ids[i];
            if (ans[tid].empty()) ans[tid].push_back(vs[0]);
        }

        for (int tid = 0; tid < id; ++tid)
          ans[tid].insert(ans[tid].end(), res[tid].begin(), res[tid].end());

        return ans;
    }
    string GetParent(unordered_map<string, string> &parents, const string &s) {
        auto p = parents.insert({s, s});
        if (p.first->second == s) return s;
        return p.first->second = GetParent(parents, p.first->second);
    }
};

int main() {
  vector<vector<string> > accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
  auto ans = Solution().accountsMerge(accounts);
  for (auto &v : ans) {
    PRINT_ARRAY(v);
  }
  return 0;
}
