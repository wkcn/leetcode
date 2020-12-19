#include "common.h"

unordered_map<char, int> MA = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};
class Solution {
public:
    int romanToInt(string s) {
        int v = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && MA[s[i]] < MA[s[i + 1]]) {
                v += MA[s[i + 1]] - MA[s[i]];
                ++i;
            } else {
                v += MA[s[i]];
            }
        }
        return v;
    }
};


int main() {
  string s;
  cin >> s;
  cout << Solution().romanToInt(s) << endl;
  return 0;
}
