// TODO: O(1)解法
// xyz: 100 * x + 10 * y + z = (99 * x + 9 * y) + (x + y + z)
// mod 9可以去掉前面的部分，如果x + y + z也能拆分，mod 9 仍然有效
// x + y + z可能为9, 但不可能为9, 原因是xyz是非负整数
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int s = 0;
            while (num > 0) {
                s += num % 10; num /= 10;
            }
            num = s;
        }
        return num;
    }
};


class Solution {
public:
    int addDigits(int num) {
        // [1, 9]
        return (num - 1) % 9 + 1;
    }
};
