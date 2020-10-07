// TODO: 其他题解方法
/*
 * 295. 数据流的中位数 - Hard
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (smaller_q.empty()) {
            smaller_q.push(num);
            return;
        }
        // larger_q.size() <= smaller_q.size() <= larger_q.size() + 1
        if (num <= smaller_q.top()) {
            smaller_q.push(num);
            if (smaller_q.size() > larger_q.size() + 1) {
                larger_q.push(smaller_q.top());
                smaller_q.pop();
            }
        } else {
            larger_q.push(num);
            if (larger_q.size() > smaller_q.size()) {
                smaller_q.push(larger_q.top());
                larger_q.pop();
            }
        }
    }
    
    double findMedian() {
        if (smaller_q.size() != larger_q.size())
            return smaller_q.top();
        return (smaller_q.top() + larger_q.top()) / 2.0;
    }
private:
    priority_queue<int> smaller_q;
    priority_queue<int, vector<int>, greater<int> > larger_q;
    // smaller_q, larger_q
};
