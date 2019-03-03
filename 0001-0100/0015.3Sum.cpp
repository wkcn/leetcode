#include "common.h"

/*
 * Runtime: 108 ms, faster than 99.94% of C++ online submissions for 3Sum.
 * Memory Usage: 16.7 MB, less than 61.42% of C++ online submissions for 3Sum.
 */
class Solution {
// reference: https://leetcode.com/problems/3sum/discuss/224990/Intuitive-C%2B%2B-Solution-with-Detailed-Comments-64-ms-Beats-99.98
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      if (nums.size() < 3) return {};
      sort(nums.begin(), nums.end());

      vector<int> forward(nums.size());
      vector<int> backward(nums.size());
      // forward
      int i, j, v;
      for (i = 1, j = 0, v = nums[0]; i < nums.size(); ++i) {
        if (v != nums[i]) {
          for (int z = j; z < i; ++z) forward[z] = i;
          v = nums[i];
          j = i;
        }
      }
      for (int z = j; z < i; ++z) forward[z] = i;

      // backward
      for (i = nums.size() - 2, j = nums.size()-1, v = nums.back(); i >= 0; --i) {
        if (v != nums[i]) {
          for (int z = i + 1; z <= j; ++z) backward[z] = i;
          v = nums[i];
          j = i;
        }
      }
      for (int z = i + 1; z <= j; ++z) backward[z] = i;


      vector<vector<int> > res;
      for (int i = 0; i < nums.size() - 2; i = forward[i]) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          int su = nums[i] + nums[j] + nums[k];
          if (su == 0) {
            res.push_back({nums[i], nums[j], nums[k]});
            j = forward[j];
            k = backward[k];
          } else {
            if (su > 0) k = backward[k];
            else j = forward[j];
          }
        }
      }
      return res;
    }
};



// 124ms, 16.4MB
class Solution3 {
// reference: https://leetcode.com/problems/3sum/discuss/224990/Intuitive-C%2B%2B-Solution-with-Detailed-Comments-64-ms-Beats-99.98
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      if (nums.size() < 3) return {};
      sort(nums.begin(), nums.end());
      vector<vector<int> > res;
      int ni_old = nums[0] - 1;
      for (int i = 0; i < nums.size() - 2; ++i) {
        if (ni_old == nums[i]) continue;
        ni_old = nums[i];
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          int su = nums[i] + nums[j] + nums[k];
          if (su == 0) {
            res.push_back({nums[i], nums[j], nums[k]});
            int x = j + 1;
            while (x < nums.size() && nums[j] == nums[x]) ++x;
            j = x;

            int y = k - 1;
            while (y >= 0 && nums[k] == nums[y]) --y;
            k = y;
          } else {
            if (su > 0) --k;
            else ++j;
          }
        }
      }
      return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      if (nums.size() < 3) return {};
      sort(nums.begin(), nums.end());
      vector<pair<int, int> > pa;
      int ni_old = nums[0] - 1;
      int nj_old = nums[0] - 1;
      for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] == ni_old) continue;
        ni_old = nums[i];
        for (int j = i+1; j < nums.size() - 1; ++j) {
          if (nums[j] == nj_old) continue;
          nj_old = nums[j];
          int g = - (nums[i] + nums[j]);
          int p = upper_bound(nums.begin() + j, nums.end(), g) - nums.begin() - 1;
          if (p > j) {
            if (g == nums[p]) {
              pa.push_back({nums[i], nums[j]});
            }
          }
        }
      }
      vector<vector<int> > res;
      for (auto &p : pa) {
        res.push_back({p.first, p.second, 0 - p.first - p.second});
      }
      return res;
    }
};

int main() {
  int n;
  cin >> n;
  vector<int> vs;
  while(n--) {
    int d;
    cin >> d;
    vs.push_back(d);
  }
  Solution so;
  vector<vector<int> > res = so.threeSum(vs);
  for (auto &vs : res) {
    cout << vs[0] << ", " << vs[1] << ", " << vs[2] << endl;
  }
  return 0;
}
