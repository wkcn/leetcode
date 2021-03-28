#include "common.h"

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
      if (m < 2 || position.size() < m) return 0;
      sort(position.begin(), position.end());
      int lo = 1, hi = position.back() - position.front() + 1;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        Check(position, mid, m) ? lo = mid + 1 : hi = mid;
      }
      return --lo;
    }
    bool Check(vector<int> &position, int max_dis, int m) {
      auto start = position.begin();
      --m;
      while (m-- > 0) {
        auto p = lower_bound(start + 1, position.end(), *start + max_dis);
        if (p == position.end()) return false;
        start = p;
      }
      return true;
    }
};

int main() {
  vector<int> v1{1, 2, 3, 4, 7};
  cout << Solution().maxDistance(v1, 3) << endl;
  vector<int> v2{5, 4, 3, 2, 1, 100000};
  cout << Solution().maxDistance(v2, 2) << endl;
  return 0;
}
