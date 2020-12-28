/*
 * 这里，我们思考一下十进制数 0~9 这 10 个数字各出现 1 次的 IP 地址（像正常情况一样，省略每组数字首位的 0。也就是说，不能像 192.168.001.002 这样表示，而要像 192.168.1.2 这样来表示）。

单选题
求用二进制数表示上述形式的 IP 地址时，能使二进制数左右对称的 IP 地址的个数（用二进制数表示时不省略 0，用完整的 32 位数表示）。

作者：图灵教育
链接：https://leetcode-cn.com/leetbook/read/interesting-algorithm-puzzles-for-programmers/9i00p1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#include "common.h"

int reverse_bits(int i) {
  int u = 0;
  for (int w = 0; w < 16; ++w) {
    u = (u << 1) | (i & 1);
    i >>= 1;
  }
  return u;
}

bool check(int i) {
  int left_16 = reverse_bits(i);
  int right_16 = i;
  array<int, 4> ip{left_16 >> 8, left_16 & 0xFF, right_16 >> 8, right_16 & 0xFF};
  array<bool, 10> used{};
  for (int e : ip) {
    for (char c : to_string(e)) {
      int v = c - '0';
      if (used[v]) return false;
      used[v] = true;
    }
  }
  for (bool b : used) if (!b) return false;
  return true;
}

int solve() {
  // 枚举一半即可
  int ans = 0;
  for (int i = 0; i <= (1 << 16); ++i) {
    if (check(i)) ++ans;
  }
  return ans;
}

int main() {
  cout << solve() << endl;
  return 0;
}
