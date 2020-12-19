#include "common.h"

class Solution {
public:
    string solveEquation(string equation) {
        int eqi = equation.find('=');
        pair<int, int> left = get_value(equation, 0, eqi);
        pair<int, int> right = get_value(equation, eqi + 1, equation.size());
        left.first -= right.first;
        left.second -= right.second;
        // ax + b = 0
        if (left.first == 0) {
            if (left.second == 0) {
                return "Infinite solutions";
            } else return "No solution";
        }
        return "x=" + to_string(-left.second / left.first);
    }
    pair<int, int> get_value(string &s, int start, int end) {
        // first * x + y
        pair<int, int> r{0, 0};
        int i = start;
        while (i < end) {
            bool minus = false;
            switch (s[i]) {
                case '-':
                    minus = true;
                case '+':
                    ++i;
                    break;
            }
            int v = 1;
            if (isdigit(s[i])) {
                int j;
                for (j = i + 1; j < end && isdigit(s[j]); ++j);
                v = stoi(s.substr(i, j - i));
                i = j;
            }
            if (minus) v = -v;
            if (i < s.size() && s[i] == 'x') {
              r.first += v;
              ++i;
            } else {
              r.second += v;
            } 
        }
        return r;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().solveEquation(s) << endl;
  return 0;
}
