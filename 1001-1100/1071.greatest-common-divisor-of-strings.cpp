// [GOOD]
// [TODO] 递归写法
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        const int len1 = str1.size();
        const int len2 = str2.size();
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(len1, len2));
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};
