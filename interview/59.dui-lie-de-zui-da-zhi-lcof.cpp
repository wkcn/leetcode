// 这个和最小栈是不一样的！！！注意最值的覆盖范围
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.empty()) return -1;
        return f.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!f.empty() && f.back() < value) f.pop_back();
        f.push_back(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int v = q.front(); q.pop();
        if (v == f.front()) f.pop_front();
        return v;
    }
private:
    queue<int> q;
    deque<int> f;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
