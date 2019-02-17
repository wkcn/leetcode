#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> vs;
      add_par(vs, "", 0, n);
      return vs;
    }
private:
    void add_par(vector<string> &vs, string prefix, int left, int num) {
      if (left == 0 && num == 0) {
        vs.push_back(prefix); 
        return;
      }
      if (num > 0)
        add_par(vs, prefix + '(', left + 1, num-1);
      if (left > 0) {
        add_par(vs, prefix + ')', left - 1, num);
      }
    }
};

int main() {
  Solution so;
  int n;
  while (cin >> n) {
    vector<string> vs = so.generateParenthesis(n);
    for (string s : vs) {
      cout << s << endl;
    }
  };
  return 0;
}
