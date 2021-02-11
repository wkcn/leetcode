// TODO: 复习这种写法，自己重新写一遍！！！！！！！
#include "common.h"

class MyMedianFinder {
public:
    /** initialize your data structure here. */
    MyMedianFinder(bool odd) : odd_(odd) {

    }
    
    void addNum(int num) {
      if (smaller_q.empty() || num <= smaller_q.top()) {
        smaller_q.push(num); ++num_smaller;
      } else {
        larger_q.push(num); ++num_larger;
      }
      makeBalance();
    }

    template <typename T>
    void prune(T& h) {
      while (!h.empty()) {
        int num = h.top();
        if (delay.count(num)) {
          if (--delay[num] == 0) {
            delay.erase(num);
          }
          h.pop();
        } else break;
      }
    }

    void makeBalance() {
      if (num_smaller > num_larger + 1) {
        larger_q.push(smaller_q.top());
        smaller_q.pop();
        --num_smaller; ++num_larger;
        prune(smaller_q);
      } else if (num_smaller < num_larger) {
        smaller_q.push(larger_q.top());
        larger_q.pop();
        ++num_smaller; --num_larger;
        prune(larger_q);
      }
    }

    void erase(int num) {
      ++delay[num];
      if (num <= smaller_q.top()) {
        --num_smaller;
        if (num == smaller_q.top()) prune(smaller_q);
      } else {
        --num_larger;
        if (num == larger_q.top()) prune(larger_q);
      }
      makeBalance();
    }
    
    double findMedian() {
        if (odd_) return smaller_q.top();
        // 先double, 避免越界
        return ((double)smaller_q.top() + larger_q.top()) / 2.0;
    }
private:
    priority_queue<int> smaller_q;
    priority_queue<int, vector<int>, greater<int> > larger_q;
    int num_smaller = 0, num_larger = 0;
    unordered_map<int, int> delay;
    bool odd_;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      vector<double> ans;
      MyMedianFinder mf(k % 2);
      for (int i = 0; i < k; ++i) {
        mf.addNum(nums[i]);
      }
      ans.push_back(mf.findMedian());
      for (int i = k; i < nums.size(); ++i) {
        mf.addNum(nums[i]);
        mf.erase(nums[i - k]);
        ans.push_back(mf.findMedian());
      }
      return ans;
    }
};

int main() {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  PRINT_ARRAY(Solution().medianSlidingWindow(nums, k));
  return 0;
}
