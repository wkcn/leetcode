class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int val;
        for (int x : nums) {
            if (cnt == 0) {
                cnt = 1;
                val = x;
            } else {
                if (x != val) --cnt;
                else ++cnt;
            }
        }
        if (cnt > 0) {
            cnt = 0;
            for (int x : nums) {
                if (x == val) ++cnt;
            }
            if (cnt * 2 > nums.size()) return val;
        }
        return -1;
    }
};
