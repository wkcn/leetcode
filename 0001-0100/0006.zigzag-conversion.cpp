#include "common.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> res(numRows);
        // numRows > 1
        const int R = numRows + numRows - 2;
        for (int i = 0; i < s.size(); ++i) {
            int r = i % R;
            if (r >= numRows) r = numRows * 2 - r - 2;
            res[r] += s[i];
        }
        return accumulate(res.begin(), res.end(), string());
    }
};

int main() {
  string s; int R;
  // cin >> s >> R;
  s = "LEETCODEISHIRING";
  R = 4;
  cout << Solution().convert(s, R) << endl;
  return 0;
}
