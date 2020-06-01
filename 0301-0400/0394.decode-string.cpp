// 记得更新下标，注意下标变量名称！
#include "common.h"

class Solution {
public:
    string decodeString(string s) {
        stack<string> str_st;
        stack<int> num_st;
        str_st.push({});
        num_st.push(1);
        int p = 0;
        const int len = s.size();
        while (p < len) {
            char c = s[p];
            if (isdigit(c)) {
                // read digit
                int start = p;
                ++p;
                while (p < len && isdigit(s[p])) ++p;
                int v = stoi(s.substr(start, p - start));
                num_st.push(v);
            } else if (c == '[') {
                str_st.push({});
                ++p;
            } else if (c == ']') {
                string e = repeat_str(str_st.top(), num_st.top());
                str_st.pop(); num_st.pop();
                str_st.top() += e;
                ++p;
            } else {
                // string
                str_st.top() += c;
                ++p;
            }
        }
        return str_st.top();
    }
    string repeat_str(string &s, int times) {
        string out;
        for (int t = 0; t < times; ++t) {
            out += s;
        }
        return out;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().decodeString(s) << endl;
  return 0;
}
