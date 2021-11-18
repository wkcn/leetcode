#include "common.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
      auto p = se.insert(num);
      if (left == se.end()) {
        left = right = se.begin();
      } else if (num < *left) {
        if (left == right) --left;
        else right = left;
      } else {
        if (left == right) ++right;
        // 当num >= *left时，num可能在left和right之间，也可能在right右边
        else if (num < *right) {
          left = right = p;
        } else left = right;
      }
    }
    
    double findMedian() {
      return (*left + *right) / 2.0;
    }
private:
    multiset<int> se;
    multiset<int>::iterator left = se.end(), right = se.end();
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
