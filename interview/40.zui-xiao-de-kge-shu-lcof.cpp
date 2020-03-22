// [TODO] 用最大堆（优先队列做）
#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
// Quick Sort
class Solution {
public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (arr.size() <= k) return arr;
    // quick sort
    int lo = 0, hi = arr.size();
    --k;
    while (lo < hi) {
      int i = lo, j = hi - 1;
      int key = arr[i];
      while (i < j) {
        while (i < j && arr[j] >= key) --j;
        arr[i] = arr[j];
        while (i < j && arr[i] <= key) ++i;
        arr[j] = arr[i];
      }
      arr[i] = key;
      if (i == k) break;
      else if (i < k) {
        lo = i + 1;
      } else hi = i;
    }
    arr.resize(k+1);
    return arr;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (arr.size() <= k) return arr;
    // min heap
    int len = arr.size();
    for (int p = len / 2 - 1; p >= 0; --p) {
      min_heapify(arr, p, len);
    }
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(arr[0]);
      arr[0] = arr[--len];
      min_heapify(arr, 0, len);
    }
    return ans;
  }
private:
  void min_heapify(vector<int> &v, int p, const int len) {
    while (1) {
      int son = p * 2 + 1;
      if (son >= len) return;
      // choose minimum son
      if (son + 1 < len && v[son] > v[son + 1]) ++son;
      if (v[p] <= v[son]) return;
      swap(v[p], v[son]);
      p = son;
    }
  }

};

#endif

int main() {
  vector<int> arr; int k;
  INPUT_ARRAY(arr); cin >> k;
  PRINT_ARRAY(Solution().getLeastNumbers(arr, k));
  return 0;
}
