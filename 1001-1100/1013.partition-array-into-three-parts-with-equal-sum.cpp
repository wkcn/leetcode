// 其实一个指针在前面数，一个在后面向前数就可以了
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int su = 0;
        for (int x:A) su += x;
        if (su % 3) return false;
        const int len = A.size();
        su /= 3;
        int cnt = 0;
        int ps = 0;
        for (int x: A) {
            ps += x;
            if (ps == su) {
                ps = 0;
                ++cnt;
            }
        }
        return cnt >= 3;
    }
};
