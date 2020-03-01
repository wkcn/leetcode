class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek();
        out_stack.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
private:
    stack<int> in_stack, out_stack;
};
