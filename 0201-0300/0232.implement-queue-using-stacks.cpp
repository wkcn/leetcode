class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek(); out_st.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        update_out();
        return out_st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        update_out();
        return out_st.empty();
    }
private:
    void update_out() {
        if (out_st.empty()) {
            while (!in_st.empty()) {
                out_st.push(in_st.top()); in_st.pop();
            }
        }
    }
private:
    stack<int> in_st, out_st;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
