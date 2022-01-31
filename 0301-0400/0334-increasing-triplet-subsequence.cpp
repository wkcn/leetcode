class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> buf;
        for (int x : nums) {
            auto p = lower_bound(buf.begin(), buf.end(), x);
            if (p == buf.end()) {
                buf.push_back(x);
                if (buf.size() >= 3) return true;
            } else *p = x;
        }
        return false;
    }
};
