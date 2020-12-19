#include "common.h"

class Solution {
public:
    // 遇到true就可以退出了
    vector<int> splitIntoFibonacci(string S) {
      vector<int> vs;
      function<bool(int)> F = [&](int start) {
        if (start >= S.size()) return vs.size() >= 3;
        if (S[start] == '0') {
          if (vs.size() >= 2 && vs[vs.size() - 2] + vs.back() != 0) {
            return false;
          }
          vs.push_back(0);
          if (F(start + 1)) return true;
          vs.pop_back();
          return false;
        }
        int v = 0;
        for (int i = start; i < S.size(); ++i) {
          if (v > INT32_MAX / 10) break;
          int m = S[i] - '0';
          // 检查是否溢出
          if (v * 10 > INT32_MAX - m) break;
          v = v * 10 + m;
          if (vs.size() >= 2) {
            if (vs[vs.size() - 2] > INT32_MAX - vs.back()) break;
            int su = vs[vs.size() - 2] + vs.back();
            if (v > su) break;
            if (v < su) continue;
          }
          vs.push_back(v);
          if (F(i + 1)) return true;
          vs.pop_back();
        }
        return false;
      };
      F(0);
      return vs;
    }
};

int main() {
  string S;
  cin >> S;
  PRINT_ARRAY(Solution().splitIntoFibonacci(S));
  return 0;
}
