#include "common.h"

int dp[1 << 16];
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
      unordered_map<string, int> ma;
      for (int i = 0; i < req_skills.size(); ++i) {
        ma[req_skills[i]] = i;
      }
      vector<int> ps(people.size());
      for (int i = 0; i < people.size(); ++i) {
        int v = 0;
        for (string &s : people[i]) {
          v |= (1 << ma[s]);
        }
        ps[i] = v;
      }
      const int M = 1 << req_skills.size();
      fill(dp, dp + M, INT32_MAX);
      dp[0] = 0;
      vector<pair<int, int> > pre(M);
      for (int p = 0; p < ps.size(); ++p) {
        int &mask = ps[p];
        for (int i = M - 1; i >= 0; --i) {
          if (dp[i] == INT32_MAX) continue;
          int u = mask | i;
          if (dp[i] + 1 < dp[u]) {
            dp[u] = dp[i] + 1;
            pre[u] = {i, p};
          }
        }
      }
      vector<int> ans;
      auto p = pre[M - 1];
      while (p.first != 0) {
        ans.push_back(p.second);
        p = pre[p.first];
      }
      ans.push_back(p.second);
      return ans;
    }
};

int main() {
  vector<string> req_skills = {"java","nodejs","reactjs"};
  vector<vector<string>> people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
  PRINT_ARRAY(Solution().smallestSufficientTeam(req_skills, people));
  return 0;
}
