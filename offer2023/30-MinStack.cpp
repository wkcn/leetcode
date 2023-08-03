class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (minv.empty() || x <= minv.top()) minv.push(x);
    }
    
    void pop() {
        int v = st.top();
        st.pop();
        if (v == minv.top()) minv.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return minv.top();
    }
private:
    stack<int> st;
    stack<int> minv;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : minv(INT32_MAX) {

    }
    
    void push(int x) {
        st.push((long long)x - minv);
        if (x < minv) {
            minv = x;
        }
    }
    
    void pop() {
        if (st.top() < 0) {
            // update to old minv
            minv = minv - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top() < 0) {
            // x < minv
            return minv;
        }
        return st.top() + minv;
    }
    
    int min() {
        return minv;
    }
private:
    stack<long long> st;
    int minv;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
