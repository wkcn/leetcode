#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      int last = nums[0];
      int valid = 1;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != last) {
          last = nums[i];
          nums[valid++] = last;
        }
      }
      return valid;
    }
};

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  Solution so;
  cout << so.removeDuplicates(vs) << endl;
  PRINT_ARRAY(vs);
  return 0;
}
