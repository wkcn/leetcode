#include "common.h"

#define SOLUTION 1

#if SOLUTION == 0
class MaxQueue {
public:
  void push(int v) {
    q.push(v);
    while (!pq.empty() && v > pq.back()) pq.pop_back(); 
    pq.push_back(v);
  }

  int size() {
    return q.size();
  }

  void pop() {
    if (q.front() == pq.front()) pq.pop_front();
    q.pop();
  }

  int max_value() {
    return pq.front();
  }
private:
  queue<int> q;
  deque<int> pq;
};

class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    const int len = num.size();
    if (len < size || size < 1) return {};
    MaxQueue q;
    vector<int> res;
    int i;
    if (len < size) size = len;
    for (i = 0; i < size; ++i) {
      q.push(num[i]);
    }
    res.push_back(q.max_value());
    for (; i < len; ++i) {
      q.pop();
      q.push(num[i]);
      res.push_back(q.max_value());
    }
    return res;
  }
};
#else

class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    const unsigned int len = num.size();
    if (len < size || size < 1) return {};
    vector<int> res;
    deque<int> iq;
    for (unsigned int i = 0; i < len; ++i) {
      while (iq.size() && num[i] >= num[iq.back()]) iq.pop_back();
      iq.push_back(i);
      while (i - iq.front() >= size) iq.pop_front();
      if (i + 1 >= size) res.push_back(num[iq.front()]);
    }
    return res;
  }
};

#endif

int main() {
  vector<int> data;
  INPUT_ARRAY(data);
  int k;
  cin >> k;
  PRINT_ARRAY(Solution().maxInWindows(data, k));
  return 0;
}
