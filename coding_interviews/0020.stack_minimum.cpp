#include "common.h"

#if 0
class Solution {
public:
    void push(int value) {
      in_st.push(value);
      if (out_st.empty() || value < out_st.top()) out_st.push(value);
    }
    void pop() {
      if (in_st.top() == out_st.top()) out_st.pop();
      in_st.pop();
    }
    int top() {
       return in_st.top(); 
    }
    int min() {
      return out_st.top();
    }
private:
    stack<int> in_st, out_st;
};

#else

#if 0
// 使用单个栈，保留冗余的曾经的最小值 
// https://blog.nowcoder.net/n/d90ec1fc69e24abcba72758e4c07d742
class Solution {
public:
    void push(int value) {
      if (st.empty()) {
        st.push(INT32_MAX);
        min_value = value;
      } else {
        if (value <= min_value) {
          st.push(min_value);
          min_value = value;
        }
      }
      st.push(value);
    }
    void pop() {
      if (st.top() == min_value) {
        st.pop();
        min_value = st.top();
      }
      st.pop();
    }
    int top() {
      return st.top();
    }
    int min() {
      return min_value;
    }
private:
    stack<int> st;
    int min_value;
};

#else

// 使用单个栈，保存与最小值的差 
// https://leetcode.com/problems/min-stack/discuss/49031/Share-my-Java-solution-with-ONLY-ONE-stack
class Solution {
public:
    void push(int value) {
      if (st.empty()) {
        st.push(0);
        min_value = value;
      } else {
        st.push(value - min_value);
        if (value < min_value) {
          min_value = value;
        }
      }
    }
    void pop() {
      if (st.top() < 0) {
        // top_value = new_min_value - old_min_value
        // so, old_min_value = new_min_value - top_value
        min_value -= st.top();
      }
      st.pop();
    }
    int top() {
      if (st.top() >= 0) return st.top() + min_value;
      return min_value;
    }
    int min() {
      return min_value;
    }
private:
    stack<int> st;
    int min_value;
};


#endif

#endif

int main() {
  Solution st;
  st.push(3);
  st.push(1);
  st.push(2);

  cout << st.top() << endl; // 2
  cout << st.min() << endl; // 1
  st.pop();

  cout << st.top() << endl; // 1 
  cout << st.min() << endl; // 1
  st.pop();
  return 0;
}
