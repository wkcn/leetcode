#include "common.h"

class Solution {
public:
    int largestPalindrome(int n) {
        // n位数*n位数，结果在2n-1 ~ 2n之间
        // 由于结果是回文数，需要枚举n位， 10^8太大了
        // 枚举n位吧
        int up = pow(10, n) - 1;
        int down = pow(10, n - 1);
        typedef long long LL;
        for (int h = 0; h < 2; ++h) {
            for (int v = up; v >= down; --v) {
                string left = to_string(v);
                string right(left.rbegin() + h, left.rend());
                LL p = stoll(left + right);
                for (LL k = up; k * k >= p; --k) {
                    if (p % k == 0) return p % 1337;
                }
            }
        }
        return -1;
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().largestPalindrome(n) << endl;
  return 0;
}
