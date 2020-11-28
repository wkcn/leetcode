#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        const int n = nums.size();
        const int B = 100;
        const int mi = *min_element(nums.begin(), nums.end());
        const int ma = *max_element(nums.begin(), nums.end());
        // 设置每个桶的长度
        const int dis = max(1, (ma - mi) / (n - 1));  // 最小为1
        // 因为最大间距 >= dis, 即使最大间距 == dis, 也能用桶之间min max的差得到, 用反证法证明!
        // 桶的数量
        const int m = (ma - mi) / dis + 1;
        vector<pair<int, int> > buckets(m, {-1, -1});
        for (int x : nums) {
            int ind = (x - mi) / dis;
            if (buckets[ind].first == -1) {
                buckets[ind] = {x, x};
            } else {
                auto &p = buckets[ind];
                p.first = min(p.first, x);
                p.second = max(p.second, x);
            }
        }
        int ans = 0;
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            if (buckets[i].first != -1) {
                if (prev != -1) {
                    ans = max(ans, buckets[i].first - prev);
                }
                prev = buckets[i].second;
            }
        }
        return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        const int n = nums.size();
        const int ma = *max_element(nums.begin(), nums.end());
        int e = 1;
        while (e <= ma) {
          vector<int> rec[10];
          for (int x : nums) {
            int r = (x / e) % 10;
            rec[r].push_back(x);
          }
          int k = 0;
          for (vector<int> &v : rec) {
            for (int x : v) {
              nums[k++] = x;
            }
          }
          if (e > INT32_MAX / 10) break;
          e *= 10;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
          ans = max(ans, nums[i] - nums[i - 1]);
        } 
        return ans;
    }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().maximumGap(nums) << endl;
  return 0;
}
