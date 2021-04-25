class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool minus = false;
        for (int x : nums) {
            if (x == 0) return 0;
            else if (x < 0) minus = !minus;
        }
        return minus ? -1 : 1;
    }
};
