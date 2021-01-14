#include "common.h"

template <int N>
int F() {
  return F<N - 1>() + F<N - 2>();
}

template <>
int F<0>() {
  return 0;
}

template <>
int F<1>() {
  return 1;
}

template <int i>
int G(int target) {
  if (target == i) return F<i>();
  return G<i + 1>(target);
}

// 要用模板设置终止条件，运行时的if是设置不了的
template <>
int G<31>(int target) {return -1;}

class Solution {
public:
    int fib(int n) {
      return G<0>(n);
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().fib(n) << endl;
  return 0;
}
