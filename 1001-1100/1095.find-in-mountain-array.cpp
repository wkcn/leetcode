#include "common.h"

class MountainArray {
public:
  MountainArray(vector<int> &nums) {
    data = std::move(nums);
  }
  int get(int index) {
    return data[index];
  }
  int length() {
    return data.size();
  }
private:
  vector<int> data;
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      // 首先找山顶
      const int size = mountainArr.length();
      int lo = 0, hi = size - 1;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1); 
        mountainArr.get(mid) < mountainArr.get(mid+1) ? lo = mid + 1 : hi = mid;
      }
      int r = my_lower_bound(mountainArr, size, 0, lo+1, target, [](const int &a, const int &b) -> int{return a < b;});
      if (r == -1) r = my_lower_bound(mountainArr, size, lo+1, size, target, [](const int &a, const int &b) -> int{return a > b;});
      return r;
    }
    int my_lower_bound(MountainArray &mountainArr, const int size, int lo, int hi, int target, int(cmp)(const int&, const int&)) {
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        cmp(mountainArr.get(mid), target) ? lo = mid + 1 : hi = mid;
      }
      return (lo < size && mountainArr.get(lo) == target) ? lo : -1; 
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  MountainArray mt(nums);
  int target;
  cin >> target;
  cout << Solution().findInMountainArray(target, mt) << endl;
  return 0;
}
