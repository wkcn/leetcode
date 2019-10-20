#include "common.h"

#if 0
class Solution {
public:
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> st;
    int i = 0;
    int size = pushV.size();
    for (int v : pushV) {
      while (i < size && !st.empty() && st.top() == popV[i]) {
        st.pop();
        ++i;
      }
      st.push(v);
    }
    while (i < size && !st.empty() && st.top() == popV[i]) {
      st.pop();
      ++i;
    }
    return i >= size;
  }
};

#else

class Solution {
public:
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> st;
    int size = pushV.size();
    for (int i = 0, j = 0; i < pushV.size(); ++i) {
      st.push(pushV[i]);
      while (j < size && !st.empty() && st.top() == popV[j]) {
        st.pop();
        ++j;
      }
    }
    return st.empty();
  }
};

#endif

int main() {
  vector<int> pushV, popV;
  INPUT_ARRAY(pushV);
  INPUT_ARRAY(popV);
  cout << Solution().IsPopOrder(pushV,popV) << endl;
  return 0;
}
