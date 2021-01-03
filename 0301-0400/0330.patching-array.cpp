// 贪心
#include "common.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // 假如已经有[1, 2, 3, ..., x - 1], 缺x, 那么就补一个x, 补完后，[1, 2x - 1]都补好了
        // 因为nums里可能有INT32_MAX, 而我们要计算2 * done + 1, 为了避免溢出用无符号
        unsigned int done = 0; // 表示[1, done]的区域已经填好了
        int ans = 0;
        int ind = 0;
        while (done < (unsigned int)n) {
            // try done + 1
            if (ind < nums.size()) {
                // [0, done] 已经填好，检查从[0, done]中选一个数字，加上nums[i]是否等于done + 1
                // 其中0代表只使用当前数字
                unsigned int r = done + 1 - nums[ind];
                if (r >= 0u && r <= done) {
                    // 如果可以选
                    done = done + nums[ind];
                    ++ind;
                    continue;
                }
            }
            // 补一个done + 1
            ++ans;
            done = 2 * done + 1;
        }
        return ans;
    }
};

int main() {
  unsigned int a = -1;
  int b = 1;
  cout << (a < b) << endl;  // 0
  vector<int> nums; int n;
  INPUT_ARRAY(nums); cin >> n;
  cout << Solution().minPatches(nums, n) << endl;
  return 0;
}
