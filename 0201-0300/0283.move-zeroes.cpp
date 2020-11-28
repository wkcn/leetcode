class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                j = max(j, i + 1);
                while (j < n && nums[j] == 0) ++j;
                if (j >= n) break;
                swap(nums[i], nums[j++]); 
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
