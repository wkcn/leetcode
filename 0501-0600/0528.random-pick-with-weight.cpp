class Solution {
public:
    Solution(vector<int>& w) {
        su.resize(w.size());
        su[0] = w[0];
        for (int i = 1; i < su.size(); ++i) {
            su[i] = su[i - 1] + w[i];
        }
        rand_max = RAND_MAX / su.size() * su.size();
    }
    
    int pickIndex() {
        int r;
        do {
            r = rand();
        } while (r >= rand_max);
        r %= su.back();
        return upper_bound(su.begin(), su.end(), r) - su.begin();
    }
private:
    vector<int> su;
    int rand_max;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
