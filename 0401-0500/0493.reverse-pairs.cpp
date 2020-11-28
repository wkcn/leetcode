// TODO: 树状数组
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        using LL = long long;
        const int n = nums.size();
        if (n == 0) return 0;
        int cnt = 0;
        vector<int> buf(n);
        std::function<void(int, int)> F = [&](int start, int end) {
            if (end - start <= 1) return;
            int mid = start + ((end - start) >> 1);
            F(start, mid); F(mid, end);
            int i = start, j = mid;
            while (i < mid && j < end) {
                // 避免溢出
                if ((LL)nums[i] > (LL)nums[j] * 2) {
                    cnt += mid - i;
                    ++j;
                } else ++i;
            }
            // merge
            copy(nums.begin() + start, nums.begin() + mid, buf.begin() + start);
            i = start, j = mid;
            int k = start;
            while (i < mid && j < end) {
                while (i < mid && (j >= end || buf[i] <= nums[j]))
                    nums[k++] = buf[i++];
                while (j < end && (i >= mid || buf[i] > nums[j]))
                    nums[k++] = nums[j++];
            }
            if (i < mid) copy(buf.begin() + i, buf.begin() + mid, nums.begin() + k);
        };
        F(0, n);
        return cnt;
    }
};
#elif SOLUTION == 2

inline int lowbit(int x) {
  return x & (-x);
}

// start at 1
template <typename T>
class BIT {
public:
  BIT(int n) : n_(n), data_(n + 1) {
  }
  T get_sum(int i) {
    T ans = 0;
    while (i > 0) {
      ans += data_[i];
      i -= lowbit(i);
    }
    return ans;
  }
  void update(int i, T value) {
    while (i <= n_) {
      data_[i] += value;
      i += lowbit(i);
    }
  }
private:
  int n_;
  vector<T> data_;
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
      using LL = long long;
      set<LL> se;
      for (int x : nums) {
        se.insert((LL)x);
        se.insert((LL)x * 2);
      }
      unordered_map<LL, int> ma;
      int k = se.size();
      for (LL x : se) {
        ma[x] = k--;
      } 
      int ans = 0;
      BIT<LL> b(se.size());
      for (int x : nums) {
        LL v = (LL)x * 2;
        // 不包括相等
        ans += b.get_sum(ma[v] - 1);
        b.update(ma[x], 1);
      }
      return ans;
    }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().reversePairs(nums) << endl;
  return 0;
}
