#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    string reverseParentheses(string s) {
      string ans;
      stack<string> st;
      for (char c : s) {
        if (c == '(') st.push("");
        else if (c == ')') {
          string t = st.top(); st.pop();
          reverse(t.begin(), t.end());
          if (st.empty()) {
            ans += t;
          } else {
            st.top() += t;
          }
        } else {
          if (st.empty()) {
            ans += c;
          } else st.top() += c;
        }
      }
      return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    string reverseParentheses(string s) {
      // 正在处理ans
      string ans;
      stack<string> st;
      for (char c : s) {
        if (c == '(') {
          st.emplace(move(ans));
        } else if (c == ')') {
          reverse(ans.begin(), ans.end());
          ans = st.top() + ans;
          st.pop();
        } else {
          ans += c;
        }
      }
      return ans;
    }
};

#elif SOLUTION == 3

// pre-process
class Solution {
public:
  string reverseParentheses(string s) {
    stack<int> st;
    // 可以用数组存
    unordered_map<int, int> ps;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else if (s[i] == ')') {
        int left = st.top(); st.pop();
        ps[i] = left;
        ps[left] = i;
      }
    }
    string ans;
    int i = 0;
    int step = 1;
    while (i < s.size()) {
      if (s[i] == '(' || s[i] == ')') {
        step = -step;
        i = ps[i] + step;
      } else {
        ans += s[i];
        i += step;
      }
    }
    return ans;
  }
};

#endif

int main() {
  cout << Solution().reverseParentheses("(abcd)") << endl;
  cout << Solution().reverseParentheses("(u(love)i)") << endl;
  cout << Solution().reverseParentheses("(ed(et(oc))el)") << endl;
  cout << Solution().reverseParentheses("a(dcb)e") << endl;
  return 0;
}
