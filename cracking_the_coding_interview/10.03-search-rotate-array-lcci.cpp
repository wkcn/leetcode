// 旋转数组[HARD]
#include "common.h"

class Solution {
public:
    int search(vector<int>& arr, int target) {
      const int len = arr.size();
      int lo = 0, hi = len-1;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (arr[mid] == arr[hi]) --hi; // 这里的等于是关键，破解[2, 1, 2, 2, 2], 2
        else arr[mid] < arr[hi] ? hi = mid : lo = mid + 1;
      }
      // back<= | <back
      // 2 1 2 2
      // 2 1 1 2
      // lo is the index of the minimum value
      // lower_bound and upper_bound
      int rot = lo;
      // lower_bound
      lo = 0, hi = len;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        arr[(mid + rot) % len] < target ? lo = mid + 1 : hi = mid; 
      }
      const int lower = (lo + rot) % len;
      if (arr[lower] != target) return -1;
      // upper_bound
      lo = 0, hi = len;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        arr[(mid + rot) % len] <= target ? lo = mid + 1 : hi = mid; 
      }
      const int upper = (lo + rot) % len;
      // [lower, upper)
      if (lower >= upper && upper > 0) return 0;
      return lower;
    }
};

int main() {
  vector<int> arr; int target;
  INPUT_ARRAY(arr); cin >> target;
  cout << Solution().search(arr, target) << endl;
  return 0;
}
