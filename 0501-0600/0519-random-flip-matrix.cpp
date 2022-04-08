class Solution {
public:
    Solution(int m, int n) : m_(m), n_(n) {
        buf.resize(m_ * n_);
        iota(buf.begin(), buf.end(), 0);
        reset();
    }
    
    vector<int> flip() {
        int r = rand() % buf_size;
        int v = buf[r];
        --buf_size;
        swap(buf[r], buf[buf_size]);
        return {v / n_, v % n_};
    }
    
    void reset() {
        buf_size = m_ * n_;
    }
private:
    int m_, n_;
    vector<int> buf;
    int buf_size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
