// 区间DP
/*
 *Removal Game

Description

Bobby Roberts is totally bored in his algorithms class, so he'sdeveloped a little solitaire game. He writes down a sequence ofpositive integers and then begins removing them one at a time. The costof each removal is equal to the greatest common divisor (gcd) of the twosurrounding numbers (wrapping around either end if necessary).

For example, if the sequence of numbers was 2, 3, 4, 5 he could removethe 3 at a cost of 2 (= gcd(2,4)) or he could remove the 4 at a cost of1 (= gcd(3,5)). Thecost of removing 2 would be 1 and the removal of 5 would cost 2.Note that if the 4 is removed first, the removal of the 3 afterwardsnow has a cost of only 1.

Bobby keeps a running total of each removal cost. When he ends up withjust two numbers remaining he takes their gcd, adds that cost to the running total,and ends the game by removing them both.The object of the game is to remove all of the numbersat the minimum total cost. Unfortunately, hespent so much time in class on this game, he didn't pay attention to severalimportant lectures which would lead him to an algorithm to solve thisproblem. Since none of you have {\em ever\/} wasted time in your algorithm classes, I'm sure you'll have noproblem finding the minimum cost given any sequence of numbers.


Input
Input contains multiple test cases.  Each test case consists of a single linestarting with an integer nn which indicates the number of values in thesequence (2 \leq n \leq 1002≤n≤100). This is followed by nn positive integerswhich make up the sequence of values in the game.  All of these integers willbe \leq 1000≤1000. Input terminates with a line containing a single 0.There are at most 1000 test cases.


Output
For each test case, display the minimum cost of removing all ofthe numbers.

Sample Input 1 
4 2 3 4 5
5 14 2 4 6 8
0

Sample Output 1
3
8
 */
#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;

int gcd(int a, int b) {
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int data[110 * 2];
int gcd_table[1010][1010];
int dp[110 * 2][110 * 2];

int main() {
  for (int i = 1; i <= 1000; ++i) {
    for (int j = i; j <= 1000; ++j) {
      int u = gcd(i, j);
      gcd_table[i][j] = u;
      gcd_table[j][i] = u;
    }
  }
  int n;
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; ++i) {
      int v;
      scanf("%d", &v);
      data[i] = data[i + n] = v;
    }
    for (int i = 0; i < n * 2; ++i) dp[i][i] = 0;
    for (int i = 0; i < n * 2; ++i) {
      for (int j = i + 1; j < n * 2; ++j) {
        dp[i][j] = dp[j][i] = INT32_MAX;
      }
    }
    // go
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i < 2 * n - len - 1; ++i) {
        for (int j = i; j < len + i; ++j) {
          if (n == len + 1)
            dp[i][i + len] = min(dp[i][i+len], dp[i][j] + dp[j+1][i+len] + gcd_table[data[i]][data[j+1]]);
          else
            dp[i][i + len] = min(dp[i][i+len], dp[i][j] + dp[j+1][i+len] + gcd_table[data[i]][data[i+len+1]]);
        }
      }
    }
    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, dp[i][i + n - 1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
