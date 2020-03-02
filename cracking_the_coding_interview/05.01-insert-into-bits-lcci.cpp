class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        if (j < i) return N;
        int len = j - i + 1;
        int mask = (1 << len) - 1;
        return (N & (~(mask << i))) | (M << i);
    }
};
