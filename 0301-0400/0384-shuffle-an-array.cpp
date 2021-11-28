class Solution {
public:
    Solution(vector<int>& nums) : init_nums(nums), state(nums) {
        
    }
    
    vector<int> reset() {
        return init_nums;
    }
    
    vector<int> shuffle() {
        const int n = state.size();
        for (int i = 0; i < n - 1; ++i) {
            int t = i + rand() % (n - i);
            swap(state[i], state[t]);
        }
        return state;
    }
private:
    vector<int> init_nums;
    vector<int> state;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
