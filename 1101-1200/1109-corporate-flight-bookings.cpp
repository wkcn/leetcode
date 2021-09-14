#include "common.h"

class Solution {
  public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 1, 0);

    for (auto &v : bookings) {
      diff[v[0]-1] += v[2];
      diff[v[1]] -= v[2];
    }

    vector<int> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += diff[i];
      ans[i] = cnt;
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> bookings{{1,2,10},{2,3,20},{2,5,25}};
  int n = 5;
  PRINT_ARRAY(Solution().corpFlightBookings(bookings, n));
  return 0;
}
