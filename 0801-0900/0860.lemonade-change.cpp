class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0; // 5, 10, 20
        for (int x : bills) {
            switch (x) {
                case 5:
                    ++a;
                    break;
                case 10:
                    if (a == 0) return false;
                    ++b;
                    --a;
                    break;
                case 20:
                    // 10 + 5或者5 * 3
                    if (b > 0 && a > 0) {
                        --a;
                        --b;
                    } else if (a >= 3) {
                        a -= 3;
                    } else return false;
                    break;
            }
        }
        return true;
    }
};
