class NumArray {
public:
    NumArray(vector<int>& nums) {
        su.resize(nums.size() + 1);
        su[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            su[i + 1] = su[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        // [i, j]
        return su[j + 1] - su[i];
    }
private:
    vector<int> su;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
