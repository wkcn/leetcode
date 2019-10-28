#include "common.h"

class Solution {
public:
  int GetUglyNumber_Solution(int index) {
    if (index == 0) return 0;
    vector<int> v(index);
    v[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < index; ++i) {
      int v2 = v[p2] * 2;
      int v3 = v[p3] * 3;
      int v5 = v[p5] * 5;
      v[i] = min(v2, min(v3, v5));
      if (v[i] == v2) ++p2;
      if (v[i] == v3) ++p3;
      if (v[i] == v5) ++p5;
    }
    return v.back();
  }
};

int main() {
  int index;
  cin >> index;
  cout << Solution().GetUglyNumber_Solution(index) << endl;
  return 0;
}
