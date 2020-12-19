#include "common.h"

unordered_map<int, char> MA = {
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'}
};
const string chars = "IVXLCDM";
class Solution {
public:
    string intToRoman(int num) {
        // 10: I and V
        // 100: X and L
        // 1000: C and D
        int i = 0;
        string ans;
        while (num > 0) {
            int y = num % 10;
            if (y <= 3) {
                ans += string(y, chars[i]);
            } else if (y == 4) {
                ans += chars[i + 1];
                ans += chars[i];
            } else if (y == 9) {
                ans += chars[i + 2];
                ans += chars[i];
            } else {
                ans += string(y - 5, chars[i]);
                ans += chars[i + 1];
            }
            i += 2;
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
  Solution so;
  for (int i = 1; i < 100; ++i) {
    cout << i << ": " << so.intToRoman(i) << endl;
  } 
  cout << so.intToRoman(1994) << endl;
  return 0;
}
