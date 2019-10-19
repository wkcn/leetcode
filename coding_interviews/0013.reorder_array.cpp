#include "common.h"

#if 0

class Solution {
public:
  void reOrderArray(vector<int> &array) {
    size_t size = array.size();
    int i;
    int j = 0;
    vector<int> even;
    for (i = 0; i < size; ++i) {
      int v = array[i];
      if (v % 2) {
        array[j++] = v;
      } else {
        even.push_back(v);
      }
    }
    for (const int &u : even) array[j++] = u;
  }
};

#else

#if 0
// bubble sort
class Solution {
public:
  void reOrderArray(vector<int> &array) {
    const size_t size = array.size();
    if (size == 0) return;
    // size_t(0) - 1 != -1
    for (int i = 0; i < size - 1; ++i) {
      for (int j = 0; j < size - 1 - i; ++j) {
        if (array[j] % 2 == 0 && array[j + 1] % 2 == 1) swap(array[j], array[j+1]);
      }
    }
  }
};
#else

// insertion sort
class Solution {
public:
  void reOrderArray(vector<int> &array) {
    const size_t size = array.size();
    if (size == 0) return;
    for (int i = 1; i < size; ++i) {
      int v = array[i];
      if (v % 2 == 1) {
        int j = i - 1;
        while (j >= 0 && array[j] % 2 == 0) {
          array[j+1] = array[j];
          --j;
        }
        array[j+1] = v;
      }
    }
  }
};

#endif

#endif

int main() {
  vector<int> v;
  INPUT_ARRAY(v);
  Solution().reOrderArray(v);
  PRINT_ARRAY(v);
  return 0;
}
