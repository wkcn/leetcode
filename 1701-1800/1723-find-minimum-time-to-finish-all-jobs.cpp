#include "common.h"


class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
      int total_job = accumulate(jobs.begin(), jobs.end(), 0);
      int lo = 0, hi = total_job + 1;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        check(jobs, k, mid) ? hi = mi : lo = mi + 1; 
      }
      return lo;
    }
    bool check(vector<int> &jobs, int k, int mid) {
    }
};

int main() {
  return 0;
}
