#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1

class MinStack {
    using LL = long long; // 注意用int会溢出！
public:
    /** initialize your data structure here. */
    MinStack(): minValue(0) {

    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(0); // 注意初值！
            minValue = x;
        } else {
            st.push(x - minValue);
            if (x < minValue) minValue = x;
        }
    }
    
    void pop() {
        LL v = st.top(); st.pop();
        if (v < 0) {
            // update minValue
            // v = minValue - old_minValue
            minValue = minValue - v;
        }
    }
    
    int top() {
        LL v = st.top();
        if (v < 0) {
            return minValue;
        }
        return v + minValue;
    }
    
    int getMin() {
        return minValue;
    }
private:
    stack<LL> st;
    LL minValue;
};

#elif SOLUTION == 2

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (st.empty() || x <= minValue) { // 要有等于号！！
            st.push(minValue);
            st.push(x);
            minValue = x;
        } else {
            st.push(x);
        }
    }

    void pop() {
        int v = st.top(); st.pop();
        if (v == minValue) {
            minValue = st.top(); st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minValue;
    }
private:
    stack<int> st;
    int minValue;
};

#endif

int main() {
  MinStack st;
  st.push(2147483647);
  st.push(-2147483648);
  cout << st.getMin() << endl;
  cout << st.top() << endl;
  return 0;
}
