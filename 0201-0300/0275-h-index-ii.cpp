#include "common.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
      int lo = 0, hi = citations.size();
      // 0, 1, 2, 3, 4
      // 0, 1, 3, 5, 6
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        const int rest = citations.size() - mid;
        rest <= citations[mid] ? hi = mid : lo = mid + 1; 
      }
      return citations.size() - lo;
    }
};

int main() {
  {
  vector<int> citations{0,1,3,5,6};
  cout << Solution().hIndex(citations) << endl;
  }

  {
  vector<int> citations{};
  cout << Solution().hIndex(citations) << endl;
  }
  return 0;
}
