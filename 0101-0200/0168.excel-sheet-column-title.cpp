// TODO: 好好理解, 为什么要减1
class Solution {
public:
    string convertToTitle(int n) {
        // 二十六进制的数字取值是[0, 25]
        // 而A~Z对应数字[1, 26]
        stack<char> st;
        while (n > 0) {
            --n;
            st.push('A' + (n % 26));
            n /= 26;
        }
        string s;
        while (!st.empty()) {
            s += st.top(); st.pop();
        }
        return s;
    }
};
