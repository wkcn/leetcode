#include "common.h"

#if 0
class Solution {
public:
  vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > result;
    int start = 1;
    int end = 1;
    int su = 1;
    while (end < sum) {
      if (su == sum) add_result(result, start, end);
      ++end;
      su += end;
      while (su > sum && start + 1 <= end) {
        su -= start; 
        ++start;
      }
    }
    return result;
  }
private:
  void add_result(vector<vector<int> > &v, const int start, const int end) {
    vector<int> r;
    for (int i = start; i <= end; ++i) r.push_back(i);
    v.emplace_back(r);
  }
};
#else

class Solution {
public:
  vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > result;
    int max_n = sqrt(2 * sum);
    for (int n = max_n; n >= 2; --n) {
      // if n is odd, sum / n - (n-1) / 2
      // if n is even, sum / n - (n-1) / 2
      if (((n & 1) && sum % n == 0) || (sum % n) * 2 == n) {
        vector<int> r;
        for (int j = 0, k = sum / n - (n - 1) / 2; j < n; ++j, ++k)
          r.push_back(k);
        result.emplace_back(r);
      }
    }
    return result;
  }
};
#endif

int main() {
  int sum;
  cin >> sum;
  vector<vector<int> > res = Solution().FindContinuousSequence(sum);
  for (vector<int> &seq : res) {
    PRINT_ARRAY(seq);
  }
  return 0;
}
