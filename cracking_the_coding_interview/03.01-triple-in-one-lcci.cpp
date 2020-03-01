class TripleInOne {
public:
    TripleInOne(int stackSize): stackSize_(stackSize) {
        data = new int[stackSize * 3];
        memset(sizes, 0, sizeof(sizes));
    }
    
    void push(int stackNum, int value) {
        if (sizes[stackNum] >= stackSize_) return;
        data[(sizes[stackNum]++) * 3 + stackNum] = value;
    }
    
    int pop(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        return data[(--sizes[stackNum]) * 3 + stackNum];
    }
    
    int peek(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        return data[(sizes[stackNum] - 1) * 3 + stackNum];
    }
    
    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }
    ~TripleInOne() {
        delete []data;
    }
private:
    int *data;
    int sizes[3];
    int stackSize_;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
