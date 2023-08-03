class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        // f(n) = f(n - 1)
        //        f(n - 1) + f(n - 2) if two words
        int a = 1, b = 1;
        for (int i = 1; i < s.size(); ++i) {
            if ((s[i-1] == '1') || (s[i-1] == '2' && s[i] <= '5')) {
                // two words
                int c = a + b;
                a = b; b = c;
            } else {
                a = b;
            }
        }
        return b;
    }
};
