#include "common.h"

#if 0
class Solution {
public:
  bool IsContinuous( vector<int> numbers ) {
    if (numbers.size() < 5) return false;
    sort(numbers.begin(), numbers.end());
    const int len = numbers.size();
    int king = 0;
    int i = 0;
    while (i < len && numbers[i] == 0) {++king; ++i;}
    if (i >= len) return true;
    int last = numbers[i++] + 1;
    for (; i < len; ++i) {
      int diff = numbers[i] - last;
      if (diff < 0) return false;
      king -= diff;
      if (king < 0) return false;
      last = numbers[i] + 1;
    }
    return true;
  }
};
#else

class Solution {
public:
  bool IsContinuous(vector<int> numbers) {
    if (numbers.size() < 5) return false;
    int flag = 0;
    int min_v = 14, max_v = -1;
    for (int v : numbers) {
      if (!v) continue;
      int f = 1 << v;
      if (flag & f) return false;
      flag |= f;
      if (v > max_v) max_v = v;
      if (v < min_v) min_v = v;
      if (max_v - min_v >= 5) return false;
    }
    return true;
  }
};
#endif

int main() {
  vector<int> numbers;
  INPUT_ARRAY(numbers);
  cout << Solution().IsContinuous(numbers) << endl;
  return 0;
}
