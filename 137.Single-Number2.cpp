#include "common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int res = 0;
      for (int i = 0; i < 32; ++i) {
        int s = 0;
        for (int &v : nums) {
          s += ((v >> i) & 1);
        }
        s %= 3;
        res |= (s << i);
      }
      return res;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution so;
  cout << so.singleNumber(nums) << endl;
  return 0;
}
