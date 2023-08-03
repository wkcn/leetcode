class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (char c: s) {
            if (c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (char c: s) if (c == ' ')cnt += 1;
        int len = s.size();
        s.resize(cnt * 2 + len);
        int j = s.size() - 1;
        int i = len - 1;
        while (i < j) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                --i;
            } else {
                s[j--] = s[i--];
            }
        }
        return s;
    }
};
