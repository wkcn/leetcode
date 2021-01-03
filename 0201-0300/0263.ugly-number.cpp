class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        for (int d : {2, 3, 5})
            while (num % d == 0) num /= d;
        return num == 1;
    }
};
