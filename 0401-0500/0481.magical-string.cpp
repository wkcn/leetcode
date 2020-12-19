#include "common.h"

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        string S = "122";
        int t = 2;
        for (int i = 3; i < n; ++i) {
            char c = S.back();
            char f = c == '1' ? '2' : '1';
            for (int k = 0; k < S[t] - '0'; ++k) S += f;
            ++t;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == '1') ++ans;
        }
        return ans;
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().magicalString(n) << endl;
  return 0;
}
