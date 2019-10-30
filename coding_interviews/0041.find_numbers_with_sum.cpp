#include "common.h"

class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    const int len = array.size();
    if (len < 2) return {};
    int i = 0, j = len - 1;
    while (i < j) {
      if (array[i] + array[j] == sum) return {array[i], array[j]};
      while (i < j && array[i] + array[j] > sum) --j;
      while (i < j && array[i] + array[j] < sum) ++i;
    }
    return {};
  }
};

int main() {
  vector<int> array;
  INPUT_ARRAY(array);
  int sum;
  cin >> sum;
  PRINT_ARRAY(Solution().FindNumbersWithSum(array, sum));
  return 0;
};
