class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (st.empty() || x <= min_value) {
            st.push(min_value);
            min_value = x;
        }
        st.push(x);
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
    
    int getMin() {
        return min_value;
    }
private:
    stack<int> st;
    int min_value;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
