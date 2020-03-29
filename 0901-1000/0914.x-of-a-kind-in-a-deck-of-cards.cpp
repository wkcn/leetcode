int counts[10001];
class Solution {
public:
    int gcd(int a, int b) {
        int c;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        memset(counts, 0, sizeof(counts));
        for (int &v : deck) ++counts[v];
        int last;
        int i;
        for (i = 0; i <= 10000; ++i) {
            if (counts[i] > 0) {
                last = counts[i];
                break;
            }
        }
        for (++i; i <= 10000; ++i) {
            if (counts[i] > 0) {
                last = gcd(last, counts[i]);
            }
        }
        return last != 1;
    }
};
