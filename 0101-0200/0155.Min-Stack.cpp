#include "common.h"

#if 0
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
      in_st.push(x);
      if (out_st.empty() || x <= out_st.top()) out_st.push(x);
    }
    
    void pop() {
      if (in_st.top() == out_st.top()) out_st.pop();
      in_st.pop();
    }
    
    int top() {
      return in_st.top();
    }
    
    int getMin() {
      return out_st.top();
    }
private:
    stack<int> in_st, out_st;
};
#else
// One Stack
// Reference: https://leetcode.com/problems/min-stack/discuss/49031/Share-my-Java-solution-with-ONLY-ONE-stack
typedef long long LL;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
      if (st.empty()) {
        min_value = x;
        st.push(0);
      } else {
        st.push(x - min_value);
        // if x - min_value < 0, x is the new minimum.
        if (x < min_value) min_value = x;
      }
    }
    
    void pop() {
      LL t = st.top(); st.pop();
      if (t < 0) min_value -= t;
    }
    
    int top() {
      LL t = st.top();
      if (t > 0) return min_value + t;
      return min_value;
    }
    
    int getMin() {
      return min_value;
    }
private:
    LL min_value;
    stack<LL> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl; //   --> Returns -3.
  minStack.pop();
  cout << minStack.top() << endl; //      --> Returns 0.
  cout << minStack.getMin() << endl; //   --> Returns -2.
}
