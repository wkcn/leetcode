class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        int i = (int)num1.size() - 1;
        int j = (int)num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int a = i < num1.size() ? num1[i--] - '0' : 0;
            int b = j < num2.size() ? num2[j--] - '0' : 0;
            carry += a + b;
            s += (carry % 10) + '0';
            carry /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
