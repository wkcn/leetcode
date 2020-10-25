class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto p = digits.rbegin();
        int carry = 1;
        while (p != digits.rend()) {
            carry = (*p += carry) / 10;
            *p %= 10;
            ++p;
        }   
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
