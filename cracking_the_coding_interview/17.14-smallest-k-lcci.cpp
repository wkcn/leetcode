#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        // quick sort
        qs(arr, 0, arr.size(), k);
        arr.resize(k);
        return arr;
    }
    void qs(vector<int> &arr, int start, int end, int k) {
        if (end - start <= 1) return; // 要注意结束条件!
        int pv = arr[start];
        int lo = start, hi = end - 1;
        while (lo < hi) {
            while (lo < hi && arr[hi] >= pv) --hi;
            arr[lo] = arr[hi];
            while (lo < hi && arr[lo] <= pv) ++lo;
            arr[hi] = arr[lo];
        }
        arr[lo] = pv;
        if (lo + 1 > k) qs(arr, start, lo, k);
        else if (lo + 1 < k) {
            qs(arr, lo + 1, end, k);
        }
    }
};
#elif SOLUTION == 2

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
      if (arr.size() <= k) return arr;
      nth_element(arr.begin(), arr.begin() + k, arr.end());
      arr.resize(k);
      return arr;
    }
};

#endif

int main() {
  vector<int> arr; int k;
  INPUT_ARRAY(arr); cin >> k;
  PRINT_ARRAY(Solution().smallestK(arr, k));
  return 0;
}
