class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int n = numBottles / numExchange;
            int r = numBottles % numExchange;
            ans += n;
            numBottles = n + r;
        }
        return ans;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 每次只换一组
        // 分别记两个变量为b和e
        // b - (n - 1)(e - 1) >= e, 这样能保证不出现b = 2, e = 3时，错误计算的情况
        // n(e - 1) <= b - 1
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
