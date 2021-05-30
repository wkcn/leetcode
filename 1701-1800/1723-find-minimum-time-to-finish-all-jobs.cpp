#include "common.h"


#define SOLUTION 2

#if SOLUTION == 1
int dp[12][1 << 12];
int ma[1 << 12];

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
      // k <= len(jobs) <= 12
      // 状态: dp[s][i] 当前处理到第i个工人, s中bit为1的工作已经被分配的最小时间
      const int m = jobs.size();
      for (int s = 0; s < (1 << m); ++s) {
        ma[s] = count_time(jobs, s);
      }
      for (int s = 0; s < (1 << m); ++s) {
        dp[0][s] = ma[s];
      }
      for (int i = 1; i < k; ++i) {
        for (int s = 1; s < (1 << m); ++s) {
          dp[i][s] = INT32_MAX;
          // 假如 s = 0b1011, s0为0000, (0001, 0010, 00011, 0100, 1001, 1010), 1011
          // 其实要括号里的数字就可以了
          for (int s0 = (s - 1) & s; s0 != 0; s0 = (s0 - 1) & s) {
            int a = ma[(~s0) & s];
            dp[i][s] = min(dp[i][s], max(dp[i - 1][s0], a));
          }
        }
      }
      return dp[k - 1][(1 << m) - 1];
    }
    int count_time(vector<int> &jobs, int s) {
      // time: O(m)
      const int m = jobs.size();
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        if (s & 1) {
          cnt += jobs[i];
        }
        s >>= 1;
      }
      return cnt;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
      sort(jobs.begin(), jobs.end(), greater<int>());
      int lo = jobs[0], hi = accumulate(jobs.begin(), jobs.end(), 0); 
      vector<int> costs(k);
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        // 初始化状态!
        fill(costs.begin(), costs.end(), 0);
        bool b = check(jobs, costs, 0, mid);
        b ? hi = mid : lo = mid + 1;
      }
      return lo;
    }
    // w是jobs的id
    bool check(vector<int> &jobs, vector<int> &costs, int w, int limit) {
      if (w >= jobs.size()) {
        return true;
      }
      for (int &cost : costs) {
        int new_cost = cost + jobs[w];
        if (new_cost <= limit) {
          int old_cost = cost;
          cost = new_cost;
          bool b = check(jobs, costs, w + 1, limit);
          cost = old_cost;
          if (b) return true;
          // 下面两个条件很重要, 一定要剪枝, 不然会超时
          if (new_cost == limit || cost == 0) {
            // 分配给后面的worker也没用
            return false;
          }
        }
      }
      return false;
    }
};

#endif

int main() {
  if (1) {
    vector<int> jobs{3, 2, 3};
    int k = 3;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;
  }
  if (1) {
    vector<int> jobs{1, 2, 4, 7, 8};
    int k = 2;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;
  }
  if (1) {
    vector<int> jobs{6518448,8819833,7991995,7454298,2087579,380625,4031400,2905811,4901241,8480231,7750692,3544254};
    int k = 4;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;
  }
  if (1) {
    vector<int> jobs{254,256,256,254,251,256,254,253,255,251,251,255};
    int k = 10;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;
  }
  return 0;
}
