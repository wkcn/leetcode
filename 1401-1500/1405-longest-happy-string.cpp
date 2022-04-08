#include "common.h"

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
      array<int, 3> cnts{a, b, c};
      array<int, 3> inds;
      auto update_inds = [&]() {
        // from largest to smallest
        for (int i = 0; i < 3; ++i) {
          inds[i] = i;
        }
        sort(inds.begin(), inds.end(), [&](int a, int b) {
            return cnts[a] > cnts[b];
        });
      };
      string ans;
      int rest = accumulate(cnts.begin(), cnts.end(), 0); 
      int cnt = 0;
      while (rest > 0) {
        update_inds();
        bool same = !ans.empty() && ans.back() - 'a' == inds[0];
        if (same && cnt == 2) {
          if (cnts[inds[1]] == 0) break;
          ans += inds[1] + 'a';
          --cnts[inds[1]];
          --rest;
          cnt = 1;
        } else {
          cnt = same ? cnt + 1 : 1;
          ans += inds[0] + 'a';
          --cnts[inds[0]];
          --rest;
        }
      }
      return ans;
    }
};

int main() {
  int a, b, c;
  while (1) {
    cin >> a >> b >> c;
    cout << Solution().longestDiverseString(a, b, c) << endl;
  }
  return 0;
}
