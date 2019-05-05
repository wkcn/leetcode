#include "common.h"

#if 0
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (nums2.empty()) return;
    int i = 0;
    while (i < m) {
      if (nums1[i] < nums2[0]) ++i; 
      else {
        int c = nums1[i];
        nums1[i] = nums2[0];
        ++i;
        int j = 1;
        for (; j < n; ++j) {
          if (nums2[j] >= c) break;
        }
        for (int k = 0; k < j - 1; ++k) {
          nums2[k] = nums2[k+1];
        }
        nums2[j - 1] = c;
      }
    }
    for (int j = 0; j < n; ++j) {
      nums1[i++] = nums2[j];
    }
  }
};
#else

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0) {
      i >= 0 && nums1[i] > nums2[j] ? nums1[k--] = nums1[i--] : nums1[k--] = nums2[j--];
    }
  }
};

#endif

int main() {
  vector<int> nums1, nums2;
  int m, n;
  INPUT_ARRAY(nums1);
  cin >> m;
  INPUT_ARRAY(nums2);
  cin >> n;
  
  Solution().merge(nums1, m, nums2, n);

  PRINT_ARRAY(nums1);
  return 0;
}
