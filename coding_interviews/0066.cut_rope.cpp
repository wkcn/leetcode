/*
 * 给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>=1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */
#include "common.h"

#define SOLUTION 1

#if SOLUTION == 0
class Solution {
public:
  int cutRope(int number) {
    if (number <= 1) return number;
    if (number <= 2) return 1;
    if (number == 3) return 2;
    vector<int> dp(number + 1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= number; ++i) {
      dp[i] = i - 2;
      for (int j = 1; j < i; ++j) {
        dp[i] = max(dp[i], dp[i - j] * dp[j]);
      } 
    }
    return dp[number];
  }
};
#elif SOLUTION == 1
class Solution {
public:
  int cutRope(int number) {
    if (number <= 1) return number;
    if (number <= 2) return 1;
    if (number == 3) return 2;
    int num_three = number / 3;
    if (number % 3 == 1) --num_three;
    int num_two = (number - num_three * 3) / 2;
    return pow(2, num_two) * pow(3, num_three);
  }
};
#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().cutRope(n) << endl;
  return 0;
}
