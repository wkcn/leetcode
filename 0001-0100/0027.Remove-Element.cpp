#include "common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int k = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) nums[k++] = nums[i];
      }
      return k;
    }
};

int main() {
  vector<int> datas;
  INPUT_ARRAY(datas);
  int val;
  cin >> val;
  Solution so;
  cout << so.removeElement(datas, val) << endl;
  PRINT_ARRAY(datas);
  return 0;
}
