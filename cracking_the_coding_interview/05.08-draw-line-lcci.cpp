// 先置为全部1再移位会更简单，注意用unsigned int
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        const int rbytes = w / 32;
        vector<int> v(length, 0);
        int start_b = x1 / 32 + y * rbytes;
        int end_b = x2 / 32 + y * rbytes;
        int mod1 = x1 % 32, mod2 = x2 % 32;
        int &u = v[start_b];
        u = (mod1 == 0 ? ~0 : ((1U << (32-mod1)) - 1));
        if (start_b == end_b) {
            u &= ~((1U << (31-mod2)) - 1);
        } else {
            int &e = v[end_b];
            e = ~((1U << (31-mod2)) - 1);
            for (int i = start_b+1; i < end_b; ++i) v[i] = ~0;
        }
        return v;
    }
};
