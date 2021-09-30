class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a, ub = b;
        while (ub != 0) {
            unsigned int uc = ua & ub;
            ua ^= ub;
            ub = uc << 1;
        }
        return ua;
    }
};
