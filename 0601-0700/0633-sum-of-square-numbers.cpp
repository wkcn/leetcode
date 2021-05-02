// 平方数之和: 双指针
class Solution {
public:
    bool judgeSquareSum(int c) {
        // a^2 + b^2 = (sqrt(c)) ^ 2
        using ULL = unsigned long long;
        ULL a = 0, b = sqrt(c);
        while (a <= b) {
            ULL su = a * a + b * b;
            if (su == c) return true;
            su < c ? ++a : --b;
        }
        return false;
    }
};
