class Solution {
public:
    bool isHappy(int n) {
        set<int> se;
        se.insert(n);
        while (n != 1) {
            int t = 0;
            while (n > 0) {
                int u = n % 10;
                t += u * u;
                n /= 10;
            }
            if (se.count(t)) return false;
            se.insert(t);
            n = t;
        }
        return true;
    }
};
