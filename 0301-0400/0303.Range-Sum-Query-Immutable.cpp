#include "common.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
      if (nums.empty()) return;
      su.resize(nums.size());
      su[0] = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        su[i] = su[i - 1] + nums[i];
      } 
    }
    
    int sumRange(int i, int j) {
      if (su.empty()) return 0;
      int low = i > 0 ? su[i-1] : 0;
      return su[j] - low;
    }
private:
    vector<int> su;
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  NumArray na(nums);
  while (1) {
    int i, j;
    cin >> i >> j;
    cout << na.sumRange(i, j) << endl;
  }
  return 0;
}
