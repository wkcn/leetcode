#include "common.h"

#define SOLUTION 6

#if SOLUTION == 1
// 244 ms, 64.5 MB
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      vector<int> days = bloomDay;
      sort(days.begin(), days.end()); // 需要先排序!
      days.resize(unique(days.begin(), days.end()) - days.begin());
      int lo = 0, hi = days.size();
      auto check = [&](int thr) -> bool {
        int v = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
          if (bloomDay[i] <= thr) ++cnt;
          else {
            v += cnt / k;
            cnt = 0;
          }
        }
        v += cnt / k;
        // cout << "THR: " << thr << ": " << v << endl;
        return v >= m;
      };
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        check(days[mid]) ? hi = mid : lo = mid + 1;
      }
      return days[lo];
    }
};
#elif SOLUTION == 2
// 256 ms, 64.5 MB
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      vector<int> days = bloomDay;
      sort(days.begin(), days.end()); // 需要先排序!
      days.resize(unique(days.begin(), days.end()) - days.begin());
      int lo = 0, hi = days.size();
      auto check = [&](int thr) -> bool {
        int v = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
          if (bloomDay[i] <= thr) {
            if (++cnt >= k) {
              ++v;
              cnt = 0;
            }
          } else cnt = 0;
        }
        return v >= m;
      };
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        check(days[mid]) ? hi = mid : lo = mid + 1;
      }
      return days[lo];
    }
};

#elif SOLUTION == 3

// 200 ms, 61.8 MB
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      int lo = INT32_MAX, hi = INT32_MIN;
      for (int x : bloomDay) {
        lo = min(lo, x);
        hi = max(hi, x);
      }
      ++hi;
      auto check = [&](int thr) -> bool {
        int v = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
          if (bloomDay[i] <= thr) {
            if (++cnt >= k) {
              ++v;
              cnt = 0;
            }
          } else cnt = 0;
        }
        return v >= m;
      };
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        check(mid) ? hi = mid : lo = mid + 1;
      }
      return lo;
    }
};

#elif SOLUTION == 4

// 164 ms, 61.8 MB
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      int lo = INT32_MAX, hi = INT32_MIN;
      for (int x : bloomDay) {
        lo = min(lo, x);
        hi = max(hi, x);
      }
      ++hi;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        check(mid, bloomDay, m, k) ? hi = mid : lo = mid + 1;
      }
      return lo;
    }
    bool check(int thr, vector<int> &bloomDay, int m, int k) {
      int v = 0;
      int cnt = 0;
      for (int i = 0; i < bloomDay.size(); ++i) {
        if (bloomDay[i] <= thr) {
          if (++cnt >= k) {
            ++v;
            cnt = 0;
          }
        } else cnt = 0;
      }
      return v >= m;
    };
};


#elif SOLUTION == 5

// 时间更长.
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      int lo = INT32_MAX, hi = INT32_MIN;
      for (int x : bloomDay) {
        lo = min(lo, x);
        hi = max(hi, x);
      }
      ++hi;
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);

        int v = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
          if (bloomDay[i] <= mid) {
            if (++cnt >= k) {
              ++v;
              cnt = 0;
            }
          } else cnt = 0;
        }
        v >= m ? hi = mid : lo = mid + 1;
      }
      return lo;
    }
};

#elif SOLUTION == 6

// 并查集
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if (m * k > bloomDay.size()) return -1;
      map<int, vector<int> > ma; 
      for (int i = 0; i < bloomDay.size(); ++i) {
        ma[bloomDay[i]].push_back(i);
      }
      const int n = bloomDay.size();
      vector<int> parents(n, -1); // -1代表还没有创建该节点
      vector<int> nums(n, 0); // 表示数量
      int flowers = 0;

      function<int(int)> get_parent = [&](int i) -> int {
        int p = parents[i];
        if (p == i) return i;
        return parents[i] = get_parent(p);
      };

      auto connect = [&](int from, unsigned int to) {
        if (to >= n || parents[to] == -1) return;
        // from 是新节点, to的parent有可能已经更新了
        // 得到to的parent
        int parent_to = get_parent(to);
        int old_flowers = nums[from] / k + nums[parent_to] / k;
        nums[from] += nums[parent_to];
        parents[parent_to] = from;
        int new_flowers = nums[from] / k;
        flowers += new_flowers - old_flowers;
      };
      for (auto &[day, v] : ma) {
        for (int i : v) {
          nums[i] = 1;
          parents[i] = i;
          // 一朵也能成功的情况
          if (k == 1) ++flowers;
          connect(i, i - 1);
          connect(i, i + 1);
          if (flowers >= m) return day;
        }
      }
      return -1;
    }
};

#endif

int main() {
  if (1) {
    vector<int> bloomDay{1, 10, 3, 10, 2};
    // 3
    cout << Solution().minDays(bloomDay, 3, 1) << endl; 
  }
  if (1) {
    vector<int> bloomDay{1, 10, 3, 10, 2};
    // -1
    cout << Solution().minDays(bloomDay, 3, 2) << endl; 
  }
  if (1) {
    vector<int> bloomDay{7, 7, 7, 7, 12, 7, 7};
    // 12
    cout << Solution().minDays(bloomDay, 2, 3) << endl; 
  }
  if (1) {
    vector<int> bloomDay{1000000000, 1000000000};
    // 1000000000
    cout << Solution().minDays(bloomDay, 1, 1) << endl; 
  }
  if (1) {
    vector<int> bloomDay{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    // 9
    cout << Solution().minDays(bloomDay, 4, 2) << endl; 
  }
  return 0;
}
