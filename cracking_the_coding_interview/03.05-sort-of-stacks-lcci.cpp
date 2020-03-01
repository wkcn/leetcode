/*
 * 栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-of-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#define SOLUTION 2

#if SOLUTION == 1
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        stack<int> tmp;
        while (!st.empty() && st.top() < val) {
            tmp.push(st.top()); st.pop();
        }
        st.push(val);
        while (!tmp.empty()) {
            st.push(tmp.top()); tmp.pop();
        }
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
    }
    
    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }
    
    bool isEmpty() {
        return st.empty();
    }
private:
    stack<int> st;
};

#elif SOLUTION == 2
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        int id = st.size();
        st.push_back(val);
        /*
            0
            1 2
            3 4 5 6
         */
        while (id != 0) {
            int p = (id - 1) >> 1;
            if (st[p] <= val) break;
            st[id] = st[p]; st[p] = val;
            id = p;
        }
    }
    
    void pop() {
        if (isEmpty()) return;
        if (st.size() == 1) {
            st.pop_back();
            return;
        }
        st[0] = st.back(); st.pop_back();
        // down
        int id = 0;
        int len = st.size();
        while (id < len) {
            int left = (id << 1) + 1;
            int right = left + 1;
            if (right < len) {
                int d = st[left] < st[right] ? left : right;
                // 注意比较的符号方向！！
                if (st[id] > st[d]) {
                    swap(st[id], st[d]);
                    id = d;
                } else break;
            } else {
                if (left < len && st[id] > st[left]) {
                    swap(st[id], st[left]);
                    id = left;
                } else break;
            }
        }
    }
    
    int peek() {
        if (isEmpty()) return -1;
        return st[0];
    }
    
    bool isEmpty() {
        return st.empty();
    }
private:
    vector<int> st;
};
#endif
