#include "common.h"

int my_gcd(int a, int b) {
  int c = a % b;
  while (c) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        // 首先, 找到满足r * n % k == 0的最小的r
        // 一遍能覆盖r * n / k个点
        // 遍数t = n / (r * n / k) = k / r
        const int len = nums.size();
        const int h = my_gcd(len, k);
        const int r = k / h;
        const int t = k / r; 
        for (int start = 0; start < t; ++start) {
            int i = start;
            int old = nums[i];
            do {
                i = (i + k) % len;
                swap(nums[i], old);
            } while (i != start);
        }
    }
};

#if SOLUTION2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        const int len = nums.size();
        if (len <= 1) return;
        int cnt = 0;
        // 注意循环条件!
        for (int start = 0; cnt < len; ++start) {
            int i = start;
            int prev = nums[start];
            do {
                int next = (i + k) % len;
                int old = nums[next];
                nums[next] = prev;
                prev = old;
                i = next;
                ++cnt;
            } while (i != start);
        }
    }
};
#endif

#if SOLUTION3
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        const int len = nums.size();
        if (len <= 1) return;
        k %= len; // 重要!!
        // ab => ba
        // (ab) ^ T = b^T * a ^ T
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
#endif

int main() {
  vector<int> nums; int k;
  INPUT_ARRAY(nums); cin >> k;
  Solution().rotate(nums, k);
  PRINT_ARRAY(nums);
  return 0;
}
