#include "common.h"

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    int ma = array[0];
    int su = array[0];
    int len = array.size();
    for (int i = 1; i < len; ++i) {
      su = max(su + array[i], array[i]);
      ma = max(su, ma);
    }
    return ma;
  }
};

int main() {
  vector<int> arr;
  INPUT_ARRAY(arr);
  cout << Solution().FindGreatestSumOfSubArray(arr) << endl;
  return 0;
}
