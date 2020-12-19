// 只需要知道序列末尾元素以及长度，就能确定一个序列
// TODO: 另外一种贪心的方法
#include "common.h"

template<typename T> 
using MinQueue = priority_queue<T, vector<T>, greater<T> >;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, MinQueue<int> > ma; // 以key结尾，记录长度. value是最小堆
        for (int x : nums) {
          auto &q = ma[x - 1];
          int last_len = 0;
          if (!q.empty()) {
            last_len = q.top();
            q.pop();
          }
          ma[x].push(last_len + 1);
        }
        for (auto &p : ma) {
          auto &q = p.second;
          if (!q.empty() && q.top() < 3) return false;
        }
        return true;
    }
};

int main() {
  vector<int> nums = {1, 2, 3, 3, 4, 5};
  cout << Solution().isPossible(nums) << endl;

  vector<int> nums2 = {1, 2, 3, 4, 4, 5};
  cout << Solution().isPossible(nums2) << endl;
  return 0;
}
