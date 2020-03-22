#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
int counts[40002];
class Solution {
public:
  int minIncrementForUnique(vector<int>& A) {
    memset(counts, 0, sizeof(counts));
    for (int x : A) ++counts[x];
    int step = 0;
    int last = 0;
    for (int i = 0; i <= 40000; ++i) {
      if (counts[i] > 1) {
        int t = counts[i] - 1;
        step += t;
        counts[i+1] += t;
      }
    }
    int r = counts[40001];
    step += r * (r-1) / 2;
    return step;
  }
};
#elif SOLUTION == 2

int nextv[80002];
class Solution {
public:
  int minIncrementForUnique(vector<int>& A) {
    if (A.empty()) return 0;
    for (int i = 0; i < 80002; ++i) nextv[i] = -1;
    int step = 0;
    for (int x: A) {
      // find pos
      int y = x;
      while (nextv[y] != -1) {
        y = nextv[y] + 1;
      }
      int z = x;
      while (nextv[z] != -1) {
        int old_z = z;
        z = nextv[z] + 1;
        nextv[old_z] = y; // update
      }
      step += y - x;
      nextv[y] = y;
    }
    return step;
  }
};

#endif

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().minIncrementForUnique(A) << endl;
  return 0;
}
