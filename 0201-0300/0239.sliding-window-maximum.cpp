#include "common.h"

template <typename T>
class MaxSlidingWindow {
public:
  bool empty() {
    return q.empty();
  }
  void push(T x) {
    q.push(x);
    while (!dq.empty() && x > dq.back()) {
      dq.pop_back();
    }
    dq.push_back(x);
  }
  void pop() {
    T v = q.front();
    if (v == dq.front()) {
      dq.pop_front();
    }
    q.pop();
  }
  T top() {
    return dq.front();
  }
private:
  deque<T> dq;
  queue<T> q;
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MaxSlidingWindow<int> q;
    for (int i = 0; i < k; ++i) {
      q.push(nums[i]);
    }
    vector<int> ans;
    ans.push_back(q.top());
    for (int i = k; i < nums.size(); ++i) {
      q.pop();
      q.push(nums[i]);
      ans.push_back(q.top());
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  PRINT_ARRAY(Solution().maxSlidingWindow(nums, k));
  return 0;
}
