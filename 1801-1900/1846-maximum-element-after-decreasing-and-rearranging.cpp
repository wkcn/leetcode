#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if (arr.empty()) return 0;
        // 总是可以重排成非递减数组
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
          // arr[i] 等于 arr[i - 1]或arr[i - 1] + 1
          int diff = arr[i] - arr[i - 1];
          if (diff > 1) {
            arr[i] = arr[i - 1] + 1;
          }
        }
        return arr.back();
    }
};
#elif SOLUTION == 2

// 计数排序
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      vector<int> cnts(arr.size() + 1, 0);
      for (int x : arr) ++cnts[min(x, (int)arr.size())];
      int s = 0;
      for (int i = 1; i <= arr.size(); ++i) {
        // cnts[i]
        s = min(i, s + cnts[i]); 
      }
      return s;
    }
};

#endif

int main() {
  {
  vector<int> arr{2,2,1,2,1};
  cout << Solution().maximumElementAfterDecrementingAndRearranging(arr) << endl;
  }
  {
  vector<int> arr{100,1,1000};
  cout << Solution().maximumElementAfterDecrementingAndRearranging(arr) << endl;
  }
  return 0;
}
