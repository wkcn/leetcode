#include "common.h"

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
      vector<vector<int>> prefer(n, vector<int>(n));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
          prefer[i][preferences[i][j]] = j;
        } 
      }
      vector<int> ps(n);
      for (auto &v : pairs) {
        int a = v[0], b = v[1];
        ps[a] = b; ps[b] = a;
      }
      int ans = 0;
      // 注意，1位朋友可能有多个更好的朋友，但不开心只有一次
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i != j && ps[i] != j) {
            if (prefer[i][j] < prefer[i][ps[i]] && prefer[j][i] < prefer[j][ps[j]]) {
              ans += 1;
              break;
            }
          }
        }
      }
      return ans;
    }
};

int main() {
  {
  int n = 4;
  vector<vector<int>> preferences = {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}}, pairs = {{0, 1}, {2, 3}};
  cout << Solution().unhappyFriends(n, preferences, pairs) << endl;
  }

  {
  int n = 4;
  vector<vector<int>> preferences = {{1,3,2},{2,3,0},{1,3,0},{0,2,1}}, pairs = {{1,3},{0,2}};
  cout << Solution().unhappyFriends(n, preferences, pairs) << endl;
  }
  return 0;
}
