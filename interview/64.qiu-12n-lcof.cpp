class Solution {
public:
    int sumNums(int n) {
        int su = 0;
        go(n, su);
        return su;
    }
    bool go(int n, int &su) {
        su += n;
        n && go(n-1, su);
        return true;
    }
};
