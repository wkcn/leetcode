#include "common.h"

class Solution {
public:
    int numJewelsInStones(string J, string S) {
      bool vis[256];
      memset(vis, 0, sizeof(bool) * 256);
      for (char j : J) vis[j] = true;
      int u = 0;
      for (char s : S) {
        if (vis[s]) ++u;
      }
      return u;
    }
};

int main() {
  Solution so;
  string J, S;
  cin >> J >> S;
  cout << so.numJewelsInStones(J, S) << endl;
  return 0;
}
