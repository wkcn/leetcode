#include "common.h"

class Solution {
// reference: https://leetcode.com/problems/valid-parentheses/discuss/9252/2ms-C%2B%2B-sloution
public:
  bool isValid(string s) {
    stack<char> ps;
    for (char &c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          ps.push(c);
          break;
        case ')':
          if (ps.empty() || ps.top() != '(') return false; else ps.pop(); break;
        case ']':
          if (ps.empty() || ps.top() != '[') return false; else ps.pop(); break;
        case '}':
          if (ps.empty() || ps.top() != '{') return false; else ps.pop(); break;
      }
    }
    return ps.empty();
  }
};

class Solution2 {
public:
  Solution2() {
    mappings['('] = ')';
    mappings['['] = ']';
    mappings['{'] = '}';
  }
  bool isValid(string s) {
    stack<char> ps;
    for (char c : s) {
      if (ps.empty()) {
        if (c == ')' || c == ']' || c == '}') return false;
        ps.push(c);
      } else {
        char t = ps.top();
        if (mappings[t] == c) {
          ps.pop();
        } else {
          ps.push(c);
        }
      }
    }
    return ps.empty();
  }
private:
  char mappings[256];
};

int main() {
  string s;
  Solution so;
  while (cin >> s) {
    cout << so.isValid(s) << endl;
  }
  return 0;
}
