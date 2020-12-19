#include "common.h"
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        // 当和最高位相等
        // 如果和最高位不相等，后面都可以填9
        vector<int> vs;
        // 因为后面还要用到N
        int M = N;
        while (M > 0) {
            vs.push_back(M % 10);
            M /= 10;
        }
        int i = vs.size() - 1; // 从高位开始
        for (; i >= 1; --i) {
            if (vs[i] > vs[i - 1]) {
                break;
            }
        }
        if (i == 0) return N;
        while (i < vs.size()) {
            if (vs[i] > vs[i - 1]) {
                --vs[i];
                ++i;
            } else break;
        }
        for (i -= 2; i >= 0; --i) {
            vs[i] = 9;
        }
        int ans = 0;
        int base = 1;
        for (int i = 0; i < vs.size(); ++i) {
            ans += vs[i] * base;
            if (i != vs.size() - 1)
                base *= 10;
        }
        return ans;

        // 1(3)234 -> 12999
        // (4)3234 -> 39999
        // 34543 -> 34499
        // 34043 -> 33999
        // 2332 -> 2299
        // 1000 
        // 减1有连环效应: 332
    }
};

int main() {
  int N;
  cin >> N;
  cout << Solution().monotoneIncreasingDigits(N) << endl;
  return 0;
}
