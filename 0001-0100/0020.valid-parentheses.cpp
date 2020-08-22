class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                char m = GetOther(c);
                if (st.empty() || st.top() != m) return false;
                st.pop();
            }
        }   
        return st.empty();
    }
    inline char GetOther(char c) {
        switch (c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        }
        return 0;
    }
};
