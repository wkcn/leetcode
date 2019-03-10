#include "common.h"

// 12ms
int recursive_time = 0;
class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int> > res;
      vector<int> buf;
      go(res, candidates, buf, 0, target);
      return res;
    }
  private:
    void go(vector<vector<int> > &res, vector<int>& candidates, vector<int>& buf, int pi, int rest) {
      ++recursive_time;
      for (int i = pi; i < candidates.size(); ++i) {
        int new_rest = rest - candidates[i];
        if (new_rest >= 0) {
          buf.push_back(candidates[i]);
          if (new_rest == 0)
            res.push_back(buf);
          else
            go(res, candidates, buf, i, new_rest);
          buf.pop_back();
        }
      }
    }
};

// 16ms
class Solution2 {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int> > res;
      vector<int> buf;
      go(res, candidates, buf, 0, target);
      return res;
    }
  private:
    void go(vector<vector<int> > &res, vector<int>& candidates, vector<int>& buf, int pi, int rest) {
      ++recursive_time;
      // assume pi < candidates.size()
      int v = candidates[pi];
      int next_rest = rest - v;
      if (next_rest >= 0) {
        buf.push_back(v);

        if (next_rest == 0)
          res.push_back(buf);
        else
          go(res, candidates, buf, pi, next_rest);

        buf.pop_back();
        if (pi + 1 < candidates.size())
          go(res, candidates, buf, pi + 1, rest);
      }
    }
};

int main() {
  vector<int> candidates;
  INPUT_ARRAY(candidates);
  int target;
  cin >> target;
  auto sol = Solution().combinationSum(candidates, target);
  for (vector<int> &vs : sol) {
    PRINT_ARRAY(vs);
  }
  cout << "RECURSIVE TIME: " << recursive_time << endl;
  return 0;
}
