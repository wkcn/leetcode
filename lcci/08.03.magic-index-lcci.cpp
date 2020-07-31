#include "common.h"

#define SOLUTION 4

#if SOLUTION == 1
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        const int len = nums.size();
        for (int i = 0; i < len; ++i) if (nums[i] == i) return i;
        return -1;
    }
};
#elif SOLUTION == 2

class Solution {
public:
  int findMagicIndex(vector<int>& nums) {
    function<int(int, int)> F;
    F = [&](int lo, int hi) {
      if (lo >= hi) return -1;
      int mid = lo + ((hi - lo) >> 1);
      /*
       * nums[mid] == mid, 解可能在[lo, mid)或mid
         nums[mid] < mid, 解可能在[lo, mid) 或 [mid + 1, hi) 
         nums[mid] > mid, 解可能在[lo, mid) 或 [mid + 1, hi)  
      */
      int left = F(lo, mid);
      if (left != -1) return left;
      if (nums[mid] == mid) return mid;
      return F(mid + 1, hi);
    };
    return F(0, nums.size());
  }
};

#elif SOLUTION == 3

class Solution {
public:
  int findMagicIndex(vector<int>& nums) {
    function<int(int, int)> F;
    F = [&](int lo, int hi) {
      if (lo >= hi) return -1;
      int mid = lo + ((hi - lo) >> 1);
      /*
       * nums[mid] == mid, 解可能在[lo, mid)或mid
         nums[mid] < mid, 解可能在[lo, nums[mid]+1) 或 [mid + 1, hi)
         nums[mid] > mid, 解可能在[lo, mid) 或 [nums[mid], hi)
      */
      if (nums[mid] == mid) {
        int left = F(lo, mid);
        if (left != -1) return left;
        return mid;
      } else if (nums[mid] < mid) {
        int left = F(lo, nums[mid] + 1);
        if (left != -1) return left;
        return F(mid + 1, hi);
      }
      int left = F(lo, mid);
      if (left != -1) return left;
      return F(nums[mid], hi);
    };
    return F(0, nums.size());
  }
};

#elif SOLUTION == 4

class Solution {
public:
  int findMagicIndex(vector<int>& nums) {
    queue<pair<int, int> > q;
    q.push({0, nums.size()});
    while (!q.empty()) {
      auto [lo, hi] = q.front(); q.pop();
      if (lo >= hi) continue;
      if (hi - lo == 1 && nums[lo] == lo) return lo;
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] == mid) {
        q.push({lo, mid});
        q.push({mid, mid + 1});
      } else if (nums[mid] < mid) {
        q.push({lo, nums[mid] + 1});
        q.push({mid + 1, hi}); 
      } else {
        q.push({lo, mid}); 
        q.push({nums[mid], hi}); 
      }
    }
    return -1;
  }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().findMagicIndex(nums) << endl;
  return 0;
}
