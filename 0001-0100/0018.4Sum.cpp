#include "common.h"

/*
 * Runtime: 12 ms, faster than 100.00% of C++ online submissions for 4Sum.
 * Memory Usage: 10.9 MB, less than 38.11% of C++ online submissions for 4Sum.
 */
class Solution {
// reference: https://leetcode.com/problems/4sum/discuss/240478/Java-100-win-no-loop-hell-commented-using-kthSum-tactic
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      if (nums.size() < 4) return {};
      sort(nums.begin(), nums.end());
      forward.resize(nums.size());
      backward.resize(nums.size());

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
      vector<int> pre_sum_list;
      add_kth(4, pre_sum_list, target, 0, nums, res);
      return res;
    }
private:
    void add_kth(int kth, vector<int> &pre_sum_list, int target, int left, vector<int> &nums, vector<vector<int> > &res) {
      if (kth == 2) {
        int j = left;
        int k = nums.size() - 1;
        if (target < nums[j] * 2 || target > nums[k] * 2) return;
        while (j < k) {
          int su = nums[j] + nums[k];
          if (su == target) {
            vector<int> p = pre_sum_list;
            p.push_back(nums[j]);
            p.push_back(nums[k]);
            res.emplace_back(p);
            j = forward[j];
            k = backward[k];
          } else {
            if (su > target) k = backward[k];
            else j = forward[j];
          }
        }
      } else {
        for (int i = left; i <= nums.size() - kth; i = forward[i]) {
          if (target < nums[i] * kth || target > nums.back() * kth) break;
          pre_sum_list.push_back(nums[i]);
          add_kth(kth - 1, pre_sum_list, target - nums[i], i + 1, nums, res);
          pre_sum_list.pop_back();
        }
      }
    } 
private:
    vector<int> forward;
    vector<int> backward;
};

/*
 * Runtime: 36 ms, faster than 87.50% of C++ online submissions for 4Sum.
 * Memory Usage: 10.8 MB, less than 52.12% of C++ online submissions for 4Sum.
 */
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      if (nums.size() < 4) return {};
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
      for (int z = 0; z < nums.size() - 3; z = forward[z]) {
        for (int i = z + 1; i < nums.size() - 2; i = forward[i]) {
          int j = i + 1;
          int k = nums.size() - 1;
          int pre_sum = nums[z] + nums[i];
          while (j < k) {
            int su = pre_sum + nums[j] + nums[k];
            if (su == target) {
              res.push_back({nums[z], nums[i], nums[j], nums[k]});
              j = forward[j];
              k = backward[k];
            } else {
              if (su > target) k = backward[k];
              else j = forward[j];
            }
          }
        }
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
  int target;
  cin >> target;
  Solution so;
  vector<vector<int> > res = so.fourSum(vs, target);
  for (auto &vs : res) {
    cout << vs[0] << ", " << vs[1] << ", " << vs[2] << ", " << vs[3] << endl;
  }
  return 0;
}
