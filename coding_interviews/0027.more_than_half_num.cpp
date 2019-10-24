#include "common.h"

class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.empty()) return 0;
    int cur = 0;
    int times = 0;
    const int size = numbers.size();
    for (int i = 0; i < size; ++i) {
      const int &v = numbers[i];
      if (times == 0) {
        cur = v;
        times = 1;
      } else if (cur == v) ++times;
      else --times; 
    }
    times = 0;
    for (const int v : numbers) if (v == cur) ++times;
    if (times > size / 2) return cur;
    return 0;
  }
};

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  cout << Solution().MoreThanHalfNum_Solution(vs) << endl;
  return 0;
}
