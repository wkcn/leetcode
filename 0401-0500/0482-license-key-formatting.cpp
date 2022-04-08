class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '-') s[j++] = toupper(s[i]);
        }
        string re;
        --j;
        int cnt = 0;
        while (j >= 0) {
            re += s[j--];
            ++cnt;
            if (cnt % k == 0 && j >= 0) re += '-';
        }
        reverse(re.begin(), re.end());
        return re;
    }
};
