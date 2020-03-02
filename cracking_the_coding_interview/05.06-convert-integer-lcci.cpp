class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int u = A ^ B;
        int cnt = 0;
        while (u) {
            u &= u - 1;
            ++cnt;
        }
        return cnt;
    }
};
