#include "common.h"

class Solution {
public:
    string countOfAtoms(string formula) {
      int i = 0;
      stack<unordered_map<string, int>> st;
      st.push({});
      auto read_num = [&]() -> int {
        if (i >= formula.size() || !isdigit(formula[i])) return 1;
        int v = 0;
        for (;i < formula.size() && isdigit(formula[i]); ++i) {
          v = v * 10 + (formula[i] - '0');
        }
        return v;
      };
      auto read_elem = [&]() -> string {
        string r(1, formula[i++]);
        for (;i < formula.size() && islower(formula[i]); ++i) {
          r += formula[i];
        }
        return r;
      };
      while (i < formula.size()) {
        char c = formula[i];
        if (c == '(') {
          ++i;
          st.push({});
        } else if (c == ')') {
          ++i;
          int num = read_num();
          auto cnts = move(st.top()); st.pop();
          for (auto &[k, v] : cnts) {
            st.top()[move(k)] += v * num;
          }
        } else {
          string elem = read_elem();
          st.top()[elem] += read_num();
        }
      }
      vector<pair<string, int>> vs(st.top().begin(), st.top().end());
      sort(vs.begin(), vs.end(), [](pair<string, int> &a, pair<string, int> &b) {
          return a.first < b.first;
      });
      string ans;
      for (auto &[k, v] : vs) {
        ans += k;
        if (v > 1) ans += to_string(v);
      }
      return ans;
    }
};

int main() {
  cout << Solution().countOfAtoms("Mg(OH)2") << endl;
  cout << Solution().countOfAtoms("H2O") << endl;
  cout << Solution().countOfAtoms("K4(ON(SO3)2)2") << endl;
  return 0;
}
