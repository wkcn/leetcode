#include "common.h"

class Solution {
public:
    int maxLength(vector<string>& arr) {
      vector<int> masks{0};
      for (string &s : arr) {
        int mask = getMask(s);
        if (mask < 0) continue;
        const int len = masks.size();
        for (int i = 0; i < len; ++i) {
          int &m = masks[i];
          // 注意优先级
          if ((mask & m) == 0) {
            masks.push_back(mask | m);
          }
        }
      }
      int ans = 0;
      for (int m : masks) {
        int a = getLen(m);
        ans = max(ans, a);
      }
      return ans;
    }
    int getMask(string &s) {
      int v = 0;
      for (char c : s) {
        int u = 1 << (c - 'a');
        if (v & u) return -1;
        v |= u;
      }
      return v;
    }
    int getLen(int m) {
      int i = 0;
      while (m) {
        m &= m - 1;
        ++i;
      }
      return i;
    }
};

int main() {
  vector<string> arr = {"un", "iq", "ue"};
  cout << Solution().maxLength(arr) << endl;
  return 0;
}
