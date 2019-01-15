// https://blog.csdn.net/MapleJam/article/details/52592444
#include "common.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len1 = nums1.size();
      int len2 = nums2.size();
      int total_len = len1 + len2;
      int mid = total_len / 2;
      if (total_len % 2 == 0) {
        return (get_kth(nums1, nums2, 0, 0, mid) + get_kth(nums1, nums2, 0, 0, mid + 1)) / 2.0;
      }
      return get_kth(nums1, nums2, 0, 0, mid + 1);
    }
private:
    int get_kth(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
      int alen = nums1.size() - i;
      int blen = nums2.size() - j;
      if (alen > blen) return get_kth(nums2, nums1, j, i, k);
      if (alen == 0) return nums2[j + k - 1];
      if (k == 1) return min(nums1[i], nums2[j]);
      int sa = min(k / 2, alen);
      int sb = k - sa;
      int pa = i + sa - 1;
      int pb = j + sb - 1;
      if (nums1[pa] < nums2[pb]) return get_kth(nums1, nums2, pa + 1, j, k - sa);
      if (nums1[pa] > nums2[pb]) return get_kth(nums1, nums2, i, pb + 1, k - sb);
      return nums1[pa];
    }
};

int main() {
  vector<int> a = {1, 2};
  vector<int> b = {3, 4};
  Solution so;
  cout << so.findMedianSortedArrays(a, b) << endl;
  return 0;
}
