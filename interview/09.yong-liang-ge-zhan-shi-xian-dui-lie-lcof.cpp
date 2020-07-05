class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in_st.push(value);
    }
    
    int deleteHead() {
        if (out_st.empty()) {
            while (!in_st.empty()) {
                out_st.push(in_st.top());
                in_st.pop();
            }
        }
        if (out_st.empty()) return -1;
        int v = out_st.top(); out_st.pop();
        return v;
    }
private:
    stack<int> in_st, out_st;
};
