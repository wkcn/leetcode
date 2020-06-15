#include "common.h"

#define SOLUTION 3
#if SOLUTION == 1
// 注意二分查找的自定义函数，注意rbegin, rend的位置
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int n = T.size();
        if (n == 0) return {};
        vector<int> ans(n);
        vector<int> ids; // 从大到小
        ids.push_back(n-1);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            auto p = upper_bound(ids.rbegin(), ids.rend(), T[i], [&T](int val, int b) {
                return val < T[b];
            });
            if (p == ids.rend()) {
                ids.resize(1); ids[0] = i;
                ans[i] = 0;
            } else {
                ans[i] = *p - i;
                if (p == ids.rbegin()) {
                    ids.push_back(i);
                } else {
                    // (rend, rbegin]
                    *(--p) = i;
                    ids.resize(ids.rend() - p);
                }
            }
        }
        return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      const int n = T.size();
      if (n == 0) return {};
      vector<int> ans(n);
      stack<int> st;
      for (int i = n - 1; i >= 0; --i) {
        int t = T[i];
        while (!st.empty() && t >= T[st.top()]) {
          st.pop();
        }
        // st is empty or t <= T[st.top()]
        if (st.empty()) ans[i] = 0;
        else ans[i] = st.top() - i; 
        st.push(i);
      }
      return ans;
    }
};
#elif SOLUTION == 3

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      const int n = T.size();
      if (n == 0) return {};
      vector<int> ans(n);
      stack<int> st;
      for (int i = 0; i < n; ++i) {
        while (!st.empty() && T[st.top()] < T[i]) {
          ans[st.top()] = i - st.top(); st.pop();
        }
        st.push(i);
      }
      while (!st.empty()) {
        ans[st.top()] = 0; st.pop();
      }
      return ans;
    }
};
#endif

int main() {
  vector<int> T;
  INPUT_ARRAY(T);
  PRINT_ARRAY(Solution().dailyTemperatures(T));
  return 0;
}
