class Solution {
public:
    int findComplement(int num) {
        int v = num;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        return num ^ v;
    }
};
