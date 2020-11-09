class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // max_queue, min_queue
        if (max_queue.empty() || num <= max_queue.top()) {
            max_queue.push(num);
            if (max_queue.size() > min_queue.size() + 1) {
                min_queue.push(max_queue.top()); max_queue.pop();
            }
        } else {
            min_queue.push(num);
            if (min_queue.size() > max_queue.size()) {
                max_queue.push(min_queue.top()); min_queue.pop();
            }
        }
    }
    
    double findMedian() {
        if (min_queue.size() == max_queue.size()) {
            return (min_queue.top() + max_queue.top()) / 2.0;
        }
        return max_queue.top();
    }
private:
    priority_queue<int> max_queue;
    priority_queue<int, vector<int>, greater<int> > min_queue;
};
