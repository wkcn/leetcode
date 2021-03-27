#include "common.h"

class NestedInteger {
  public:
   // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
      return is_integer_;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
   // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
      return v_;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
   // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
      return values_;
    }
    NestedInteger(int v) : is_integer_(true), v_{v}{
    }
    NestedInteger(vector<NestedInteger> &&v) : is_integer_(false), values_(v) {
    }
  private:
    bool is_integer_;
    int v_;
    vector<NestedInteger> values_;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      st.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
      hasNext();
      int v = st.top().first->getInteger();
      ++st.top().first;
      return v;
    }
    
    bool hasNext() {
      while (!st.empty()) {
        auto p = st.top();
        if (p.first == p.second) {
          st.pop();
        } else {
          if (p.first->isInteger()) {
            return true;
          } else {
            // list
            ++st.top().first;
            const auto &li = p.first->getList();
            st.push({li.begin(), li.end()});
          }
        }
      }
      return false;
    }
private:
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> st;
};

int main() {
  vector<NestedInteger> data{NestedInteger(1), NestedInteger(2), NestedInteger{{NestedInteger(3), NestedInteger(4)}}};
  NestedIterator it(data);
  while (it.hasNext()) cout << it.next() << endl;
}
