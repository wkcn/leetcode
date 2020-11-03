#include "common.h"

#define SOLUTION 3
#if SOLUTION == 1
class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
      // 预处理
      unordered_map<int, set<int> > ma;
      for (int i = 0; i < docs.size(); ++i) {
        for (int c : docs[i]) {
          ma[c].insert(i);
        }
      }
      vector<string> ans;
      for (int i = 0; i < docs.size(); ++i) {
        unordered_map<int, int> inters;
        for (int c : docs[i]) {
          for (int j : ma[c]) {
            if (i < j)
              ++inters[j];
          }
        }
        for (auto p : inters) {
          float sim = (float)p.second / (docs[i].size() + docs[p.first].size() - p.second);
          push_ans(ans, i, p.first, sim); 
        }
      }
      return ans;
    }
    void push_ans(vector<string> &ans, int i, int j, float sim) {
        stringstream ss;
        ss << i << ',' << j << ": " << fixed << setprecision(4) << sim + 1e-9;
        ans.emplace_back(ss.str());
    }
};
#elif SOLUTION == 2

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
      vector<pair<int, int> > vs;
      for (int i = 0; i < docs.size(); ++i) {
        set<int> se;
        for (int c : docs[i]) {
          if (se.insert(c).second)
            vs.push_back({c, i});
        }
      }
      sort(vs.begin(), vs.end());
      const int n = docs.size();
      const int m = vs.size();
      vector<vector<int> > inters(n, vector<int>(n, 0));
      int i = 0, j;
      while (i < m) {
        for (j = i + 1; j < m && vs[i].first == vs[j].first; ++j) {}
        // [i, j)
        for (int a = i; a < j; ++a) {
          for (int b = a + 1; b < j; ++b) {
            ++inters[vs[a].second][vs[b].second];
          }
        }
        i = j;
      }
      vector<string> ans;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (inters[i][j] > 0) {
            float sim = (float)inters[i][j] / (docs[i].size() + docs[j].size() - inters[i][j]);
            push_ans(ans, i, j, sim);
          }
        }
      }
      return ans;
    }
    void push_ans(vector<string> &ans, int i, int j, float sim) {
        stringstream ss;
        ss << i << ',' << j << ": " << fixed << setprecision(4) << sim + 1e-9;
        ans.emplace_back(ss.str());
    }
};

#elif SOLUTION == 3


class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
      vector<pair<int, int> > vs;
      for (int i = 0; i < docs.size(); ++i) {
        for (int c : docs[i])
            vs.push_back({c, i});
      }
      sort(vs.begin(), vs.end());
      const int n = docs.size();
      const int m = vs.size();
      vector<vector<int> > inters(n, vector<int>(n, 0));
      int i = 0, j;
      while (i < m) {
        for (j = i + 1; j < m && vs[i].first == vs[j].first; ++j) {}
        // [i, j)
        for (int a = i; a < j; ++a) {
          for (int b = a + 1; b < j; ++b) {
            if (vs[a].second < vs[b].second)
              ++inters[vs[a].second][vs[b].second];
          }
        }
        i = j;
      }
      vector<string> ans;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (inters[i][j] > 0) {
            float sim = (float)inters[i][j] / (docs[i].size() + docs[j].size() - inters[i][j]);
            push_ans(ans, i, j, sim);
          }
        }
      }
      return ans;
    }
    void push_ans(vector<string> &ans, int i, int j, float sim) {
        stringstream ss;
        ss << i << ',' << j << ": " << fixed << setprecision(4) << sim + 1e-9;
        ans.emplace_back(ss.str());
    }
};


#endif

int main() {
  vector<vector<int> > docs = {
    {14, 15, 100, 9, 3},
    {32, 1, 9, 3, 5},
    {15, 29, 2, 6, 8, 7},
    {7, 10}
  };
  for (string &s : Solution().computeSimilarities(docs)) {
    cout << s << endl;
  }
  return 0;
}
