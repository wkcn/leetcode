/*
 * 堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。

当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，popAt 应返回 -1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stack-of-plates-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class StackOfPlates {
public:
    StackOfPlates(int cap): cap_(cap) {

    }
    
    void push(int val) {
        if (cap_ <= 0) return; // 注意cap <= 0的情况
        if (stacks.empty() || stacks.back().size() == cap_) {
            stacks.push_back({});
        }
        stacks.back().push(val);
    }
    
    int pop() {
        if (stacks.empty()) return -1; // 异常返回
        int v = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        return v;
    }
    
    int popAt(int index) {
        if (index >= stacks.size()) return -1;
        int v = stacks[index].top();
        stacks[index].pop();
        if (stacks[index].empty()) {
            stacks.erase(stacks.begin() + index);
        }
        return v;
    }
private:
    vector<stack<int> > stacks;
    int cap_;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
