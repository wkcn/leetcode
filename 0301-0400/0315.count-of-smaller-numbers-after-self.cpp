#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int len = nums.size();
        if (len == 0) return {};
        vector<int> tmp(len), tmpi(len);
        vector<int> out(len, 0);
        // 需要记录原来的下标
        vector<int> inds(len);
        iota(inds.begin(), inds.end(), 0);
        function<void(int, int)> F;
        // 从大到小merge sort
        F = [&](int start, int end) {
            if (end - start <= 1) return;
            int mid = start + ((end - start) >> 1);
            F(start, mid);
            F(mid, end);
            for (int i = start; i < mid; ++i) {
                tmp[i] = nums[i];
                tmpi[i] = inds[i];
            }
            int i = start, j = mid, k = start;
            while (i < mid && j < end) {
                while (i < mid && tmp[i] > nums[j]) {
                    // 注意这里用的是tmpi[i]而不是inds[i]
                    out[tmpi[i]] += end - j;
                    inds[k] = tmpi[i];
                    nums[k++] = tmp[i++];
                }
                if (i >= mid) break;
                while (j < end && tmp[i] <= nums[j]) {
                    inds[k] = inds[j];
                    nums[k++] = nums[j++];
                }
            }
            while (i < mid) {
                inds[k] = tmpi[i];
                nums[k++] = tmp[i++];
            }
        };
        F(0, len);
        return out;
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
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> tmp = nums;
      sort(tmp.begin(), tmp.end());
      tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
      unordered_map<int, int> ma;
      for (int i = 0; i < tmp.size(); ++i) {
        ma[tmp[i]] = i + 1;
      }
      BIT<int> tree(ma.size());
      vector<int> out(nums.size());
      for (int i = nums.size() - 1; i >= 0; --i) {
        int v = ma[nums[i]];
        out[i] = tree.get_sum(v - 1); // 不包括和自己相等的值
        tree.update(v, 1);
      }
      return out;
    }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  PRINT_ARRAY(Solution().countSmaller(nums));
  return 0;
}
