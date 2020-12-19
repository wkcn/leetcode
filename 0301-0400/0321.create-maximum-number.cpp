#include "common.h"

class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    if (k == 0) return {};
    const int m = nums1.size();
    const int n = nums2.size();
    /*
     * nums1中选出a个， num2中选出b个
     * a + b = k
     * 0 <= a <= m, 0 <= b <= n
     * 0 <= b <= n -> 0 <= k - a <= n
     * -> a <= k, a >= k - n
     */
    int start = max(k - n, 0); 
    int end = min(k, m);
    vector<int> ans(k, INT32_MIN);
    for (int a = start; a <= end; ++a) {
      vector<int> v1 = GetSeq(nums1, a);
      vector<int> v2 = GetSeq(nums2, k - a);
      int i = 0, j = 0;
      int v;
      int p = 0;
      bool first = true;
      while (i < v1.size() || j < v2.size()) {
        if (CompareLess(v1, v2, i, j)) {
          v = v1[i++];
        } else {
          v = v2[j++];
        }
        if (first) {
          if (v < ans[p]) {
            break;
          } else if (v > ans[p]) {
            ans[p] = v;
            first = false;
          }
          ++p;
        } else {
          ans[p++] = v;
        }
      }
    }
    return ans;
  }
  bool CompareLess(vector<int> &a, vector<int> &b, int &i, int &j) {
    if (i >= a.size()) return false;
    if (j >= b.size()) return true;
    int i2 = i, j2 = j;
    while (i2 < a.size() && j2 < b.size()) {
      if (a[i2] < b[j2]) {
        return false;
      } else if (a[i2] > b[j2]) {
        return true;
      }
      ++i2;
      ++j2;
    }
    return i2 < a.size();
  }
  vector<int> GetSeq(vector<int> &nums, int k) {
    if (k == 0) return {};
    int drop = nums.size() - k;
    vector<int> res(k); 
    int p = 0;
    for (int x : nums) {
      while (drop > 0 && p > 0 && x > res[p - 1]) {
        --drop;
        --p;
      }
      if (p < k)
        res[p++] = x;
      else --drop;  // 没加进去的也算被丢弃！
    }
    return res;
  }
};

int main() {
  /*
  vector<int> nums1 = {3, 4, 6, 5};
  vector<int> nums2 = {9, 1, 2, 5, 8, 3};
  int k = 5;
  vector<int> nums1 = {2,8,0,4,5,1,4,8,9,9,0,8,2,9};
  vector<int> nums2 = {5,9,6,6,4,1,0,7};
  int k = 22;
  */
  vector<int> nums1 = {7, 6, 1, 9, 3, 2, 3, 1, 1};
  vector<int> nums2 = {4, 0, 9, 9, 0, 5, 5, 4, 7};
  int k = 9;
  PRINT_ARRAY(Solution().maxNumber(nums1, nums2, k));
  return 0;
}
