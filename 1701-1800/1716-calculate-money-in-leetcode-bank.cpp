class Solution {
public:
    int totalMoney(int n) {
        /*
            1 2 3 4 5 6 7
            2 3 4 5 6 7 8
            3 4 5

            n = 17
            r = 2, c = 3
         */
         int r = n / 7, c = n % 7;
         return (1 + 7) * 7 / 2 * r + 7 * (0 + r - 1) * r / 2 + \
            (r + 1 + r + c) * c / 2;
    }
};
