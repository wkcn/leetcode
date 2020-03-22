// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
#include "common.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 1;
        int sum = 0; // [left, right)
        const int half = (target + 1) / 2;
        vector<vector<int> > ans;
        while (left < half) {
            if (sum == target) {
                vector<int> buf;
                for (int i = left; i < right; ++i) {
                    buf.push_back(i);
                }
                ans.emplace_back(buf);
                // 注意枚举下一个结果
                sum += right++;
                sum -= left++;
            } else if (sum < target) {
                sum += right++;
            }
            else sum -= left++;
        }
        return ans;
    }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int> > ans = Solution().findContinuousSequence(n);
  for (vector<int> &a : ans) {
    PRINT_ARRAY(a);
  }
  return 0;
}
