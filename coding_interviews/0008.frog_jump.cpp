#include "common.h"

#if 0
class Solution {
public:
  int jumpFloor(int number) {
    vector<int> v(number);
    v[0] = 1;
    v[1] = 2; 
    for (int i = 2; i < number; ++i) v[i] = v[i-1] + v[i-2];
    return v[number-1];
  }
};
#else

#if 0
class Solution {
public:
  int jumpFloor(int number) {
    if (number <= 2) return number;
    int a[3] = {0, 1, 2};
    int i = 2;
    --number;
    while (--number) {
      i = (i + 1) % 3;
      a[i] = a[(i+1)%3] + a[(i+2)%3];
    }
    return a[i];
  }
};
#else

class Solution {
public:
  int jumpFloor(int number) {
    if (number <= 2) return number;
    int pre2 = 1;
    int pre1 = 2;
    for (int i = 2; i < number; ++i) {
      int cur = pre1 + pre2;
      pre2 = pre1;
      pre1 = cur;
    }
    return pre1;
  }
};

#endif

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().jumpFloor(n) << endl;
  return 0;
}
