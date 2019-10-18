#include "common.h"

class Solution
{
  public:
    void push(int node) {
      stack1.push(node);
    }

    int pop() {
      if (stack2.empty()) {
        while (!stack1.empty()) {
          stack2.push(stack1.top());
          stack1.pop();
        }
      }
      int v = stack2.top();
      stack2.pop();
      return v;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
  Solution q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout << q.pop() << endl;
  q.push(4);
  cout << q.pop() << endl;
  q.push(5);
  q.push(6);
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  return 0;
}
