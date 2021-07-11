#include "common.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
      /*
       * 0, 1, 2, 3, 4
       * 5, 4, 3, 2, 1
       * 0, 1, 3, 5, 6
       */
      sort(citations.begin(), citations.end());
      int lo = 0, hi = citations.size();
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        int rest = citations.size() - mid;
        citations[mid] < rest ? lo = mid + 1 : hi = mid;
      }
      return citations.size() - lo;
    }
};

int main() {
  vector<int> citations{3,0,6,1,5};
  cout << Solution().hIndex(citations) << endl;
  return 0;
}
