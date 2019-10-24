#include "common.h"

void heap_down(vector<int> &a, int k) {
  int len = a.size();
  int left = 2 * k + 1;
  int right = 2 * k + 2;
  int r = k;
  if (left < len && a[r] < a[left]) r = left;
  if (right < len && a[r] < a[right]) r = right;
  if (r != k) {
    swap(a[r], a[k]);
    heap_down(a, r);
  }
}

// Max Heap
void my_make_heap(vector<int> &a) {
  int len = a.size();
  for (int i = (len - 1) / 2; i >= 0; --i) {
    heap_down(a, i);
  }
}

void heap_up(vector<int> &a, int k) {
  if (k == 0) return;
  int p = (k - 1) / 2;
  if (a[p] < a[k]) {
    swap(a[p], a[k]);
    heap_up(a, p);
  }
}

void my_push_heap(vector<int> &a, int val) {
  a.push_back(val);
  heap_up(a, a.size()-1);
}

int my_pop_head(vector<int> &a) {
  int v = a[0];
  a[0] = a.back();
  a.pop_back();
  // Notice! a may be empty after pop
  if (a.size() > 1)
    heap_down(a, 0);
  return v;
}

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    // OUTLIER!!!!
    if (input.size() < k || k == 0) return {}; 
    int len = input.size();
    vector<int> heap(input.begin(), input.begin() + min(k, len)); // max_heap
    my_make_heap(heap);
    for (int i = k; i < len; ++i) {
      int v = input[i];
      if (v < heap[0]) {
        my_pop_head(heap);
        my_push_heap(heap, v);
      }
    }
    sort(heap.begin(), heap.end());
    return heap;
  }
};

int main() {
  int k;
  cin >> k;
  vector<int> v;
  INPUT_ARRAY(v);
  PRINT_ARRAY(Solution().GetLeastNumbers_Solution(v, k));
  return 0;
}
