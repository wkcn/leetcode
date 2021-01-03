class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        int i = 0, j;
        while (i < nums.size()) {
            for (j = i + 1; j < nums.size() && nums[i] == nums[j]; ++j);
            int cnt = min(j - i, 2);
            while (cnt-- > 0) nums[p++] = nums[i];
            i = j;
        }
        return p;
    }
};
