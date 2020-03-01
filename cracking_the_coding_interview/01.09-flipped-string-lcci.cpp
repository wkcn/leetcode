class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        string s3 = s2 + s2;
        return s3.find(s1) != string::npos;
    }
};
