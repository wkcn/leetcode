class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res;
        while (carry > 0 || i >= 0 || j >= 0) {
            int left = i >= 0 ? a[i--] - '0': 0;
            int right = j >= 0 ? b[j--] - '0': 0;
            int v = left + right + carry;
            if (v & 1) res += '1';
            else res += '0';
            carry = (v & 0b10) != 0; // 注意这里！
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
