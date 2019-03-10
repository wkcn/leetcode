#include "common.h"

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() > b.size()) return addBinary(b, a);
    stack<bool> st;
    bool jw = 0;
    // a.size() < b.size()
    auto a_iter = a.rbegin();
    auto b_iter = b.rbegin();
    for (;a_iter != a.rend();++a_iter, ++b_iter) {
      bool va = *a_iter - '0';
      bool vb = *b_iter - '0';
      st.push(va ^ vb ^ jw);
      jw = (va && vb) || (jw && (va || vb)); 
    }
    for (;b_iter!=b.rend();++b_iter) {
      bool vb = *b_iter - '0';
      st.push(vb ^ jw);
      jw = vb && jw;
    }
    if (jw) st.push(jw);
    string res;
    res.resize(st.size());
    for (int i = 0; i < res.size(); ++i) {
      res[i] = st.top() + '0';
      st.pop();
    }
    return res;
  }
};

int main() {
  string a, b;
  cin >> a >> b;
  cout << Solution().addBinary(a, b) << endl;
  return 0;
}
