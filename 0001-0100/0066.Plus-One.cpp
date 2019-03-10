#include "common.h"

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int jw = 1;
    for(int i = digits.size() - 1; i >= 0; --i) {
      jw = digits[i] + jw;
      digits[i] = jw % 10;
      jw /= 10;
    }
    if (jw > 0) {
      digits.resize(digits.size() + 1);
      for (int i = digits.size() - 2; i >=0; --i) {
        digits[i + 1] = digits[i];
      }
      digits[0] = jw;
    }
    return digits;
  }
};

int main() {
  vector<int> digits;
  INPUT_ARRAY(digits);
  PRINT_ARRAY(Solution().plusOne(digits));
  return 0;
}
