#include "common.h"

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  int c = a % b;
  while (c) {
    a = b;
    b = c;
    c = a % b;
  };
  return b;
}

void simplify(pair<int, int> &p) {
  if (p.first == 0) {
    p.first = 0;
    p.second = 1;
  } else {
    int w = gcd(abs(p.first), p.second);
    p.first /= w;
    p.second /= w;
  }
}

class Solution {
public:
    string fractionAddition(string expression) {
      int i = 0;
      const int n = expression.size();
      int up, down;
      vector<pair<int, int> > vs;
      while (i < n) {
        bool minus = false;
        switch (expression[i]) {
          case '-':
            minus = true;
            ++i;
            break;
          case '+':
            ++i;
            break;
        }
        // read num
        int j = i + 1;
        for (; j < n && isdigit(expression[j]); ++j);
        up = stoi(expression.substr(i, j - i));
        if (minus) up *= -1;
        i = j + 1;
        j = i + 1;
        for (; j < n && isdigit(expression[j]); ++j);
        down = stoi(expression.substr(i, j - i));
        i = j;
        vs.push_back({up, down});
      }
      pair<int, int> ans = vs[0];
      simplify(ans);

      for (int i = 1; i < vs.size(); ++i) {
        pair<int, int> &u = vs[i];
        ans.first = ans.first * u.second + ans.second * u.first; 
        ans.second *= u.second;
        simplify(ans);
      }
      return to_string(ans.first) + '/' + to_string(ans.second);
    }
};

int main() {
  string s = "-1/2+1/2+1/3";
  cout << Solution().fractionAddition(s) << endl;
  return 0;
}
