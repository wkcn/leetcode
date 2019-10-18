#include "common.h"

#if 0
class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
      if (rotateArray.empty()) return 0;
      int lo = 0;
      int hi = rotateArray.size();
      int min_v = rotateArray[0];
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int val = rotateArray[mid];
        if (val < min_v) min_v = val;
        int front = rotateArray[lo];
        if (front <= val) {
          if (front < min_v) min_v = front;
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
      return min_v;
    }
};
#else

class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
      if (rotateArray.empty()) return 0;
      int lo = 0;
      int hi = rotateArray.size();
      // find min
      while (lo < hi) {
        if (rotateArray[lo] < rotateArray[hi-1]) return rotateArray[lo]; 
        int mid = lo + (hi - lo) / 2;
        int val = rotateArray[mid];
        if (rotateArray[lo] <= val) {
          lo = mid + 1;
        } else {
          if (rotateArray[mid-1] > rotateArray[mid]) return rotateArray[mid];
          hi = mid;
        }
      }
      return rotateArray[--lo];
    }
};

#endif

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  cout << Solution().minNumberInRotateArray(vs) << endl;
  return 0;
}
