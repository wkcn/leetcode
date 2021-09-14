#include "common.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
      if (qmin.empty() || num >= qmin.top()) {
        qmin.push(num);
        if (qmin.size() > qmax.size() + 1) {
          qmax.push(qmin.top()); qmin.pop();
        }
      } else {
        qmax.push(num);
        if (qmax.size() > qmin.size()) {
          qmin.push(qmax.top()); qmax.pop();
        }
      }
    }
    
    double findMedian() {
      if (qmax.size() == qmin.size()) return (qmax.top() + qmin.top()) / 2.0;
      return qmin.top();
    }
private:
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int>> qmin;
    // qmax + qmin
};

int main() {
  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(2);
  cout << mf.findMedian() << endl;
  mf.addNum(3);
  cout << mf.findMedian() << endl;
  return 0;
}
