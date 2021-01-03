#include "common.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        --m, --n;
        while (m >= 0 && n >= 0) {
            if (nums1[m] <= nums2[n]) {
                nums1[p--] = nums2[n--];
            } else nums1[p--] = nums1[m--];
        }
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
    }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0}; int m = 3;
  vector<int> nums2 = {2, 5, 6}; int n = 3;
  Solution().merge(nums1, m, nums2, n);
  PRINT_ARRAY(nums1); 
  return 0;
}
