#include "common.h"
#include <cassert>

// 二分搜索设计时注意是看两侧是否满足条件，不变式

// Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
template <class ForwardIterator, class T>
ForwardIterator my_lower_bound(ForwardIterator first, ForwardIterator last,
                               const T& val) {
  // x < val |[lo, hi)| [hi] val <= x
  int lo = 0, hi = last - first, mid;
  while (lo < hi) {
    mid = lo + ((hi - lo) >> 1);
    T &mid_val = *(first + mid);
    mid_val < val ? lo = mid+1 : hi = mid;
  }
  return first + hi;
}

// Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
template <class ForwardIterator, class T>
ForwardIterator my_upper_bound(ForwardIterator first, ForwardIterator last,
                               const T& val) {
  // x <= val |[lo, hi)| [hi] val < x
  int lo = 0, hi = last - first, mid;
  while (lo < hi) {
    mid = lo + ((hi - lo) >> 1);
    T &mid_val = *(first + mid);
    mid_val <= val ? lo = mid+1 : hi = mid;
  }
  return first + hi;
}

template <class ForwardIterator, class T>
void check(ForwardIterator begin, ForwardIterator iter_a, ForwardIterator iter_b, T val) {
  if (iter_a != iter_b) {
    cout << "Error: " << "val=" << val << endl;
    cout << iter_a - begin << ", " << iter_b - begin << endl;
  }
}

void test_lower_bound(vector<int> &data, int val) {
  check(data.begin(), lower_bound(data.begin(), data.end(), val), my_lower_bound(data.begin(), data.end(), val), val);
}

void test_upper_bound(vector<int> &data, int val) {
  check(data.begin(), upper_bound(data.begin(), data.end(), val), my_upper_bound(data.begin(), data.end(), val), val);
}

int main() {
  vector<int> data = {1, 2, 3, 3, 3, 3, 5, 7, 7, 8, 10, 10};
  vector<int> test_num = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15};
  for (int u : test_num) {
    test_lower_bound(data, u);
  }
  for (int u : test_num) {
    test_upper_bound(data, u);
  }
  return 0;
}
