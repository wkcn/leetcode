// Binary Indexed Tree(B.I.T), Fenwick Tree
// reference: https://www.cnblogs.com/findview/archive/2019/08/01/11281628.html
#include "common.h"

inline int lowbit(int x) {
  return x & (-x);
}

// start at 1
template <typename T>
class BIT {
public:
  BIT(int n) : n_(n), data_(n + 1) {
  }
  T get_sum(int i) {
    T ans = 0;
    while (i > 0) {
      ans += data_[i];
      i -= lowbit(i);
    }
    return ans;
  }
  void update(int i, T value) {
    while (i <= n_) {
      data_[i] += value;
      i += lowbit(i);
    }
  }
private:
  int n_;
  vector<T> data_;
};

int main() {
  const int N = 100;
  vector<int> data(N); 
  for (int i = 0; i < N; ++i) {
    data[i] = rand() % 2000 - 1000;
  }
  vector<int> presum(N + 1);
  presum[0] = 0;
  for (int i = 0; i < N; ++i) {
    presum[i + 1] = presum[i] + data[i];
  }
  BIT<int> bit(N);
  for (int i = 0; i < N; ++i) {
    bit.update(i + 1, data[i]);
  }
  cout << "START TEST" << endl;
  for (int len = 1; len < N; ++len) {
    int target = presum[len];
    int bv = bit.get_sum(len);
    assert(bv == target);
  }
  cout << "TEST OVER" << endl;
  return 0;
}
