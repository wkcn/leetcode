class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        vector<char> st;
        for (int i = 0; i < num.size(); ++i) {
            char v = num[i];
            while (k > 0 && !st.empty() && st.back() > v) {
                st.pop_back();
                --k;
            }
            st.push_back(v);
        }
        auto p = st.begin();
        while (p < st.end() && *p == '0') {
            ++p;
        }
        if (p == st.end()) return "0";

        // 记得最后减k
        return string(p, st.end() - k);
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        string st;
        for (int i = 0; i < num.size(); ++i) {
            char v = num[i];
            while (k > 0 && !st.empty() && st.back() > v) {
                st.pop_back();
                --k;
            }
            st.push_back(v);
        }
        int i = 0;
        while (i < st.size() && st[i] == '0') ++i;
        const int len = st.size() - k - i;
        // 处理len == 0时
        if (len == 0) return "0";
        return st.substr(i, len);
    }
};
