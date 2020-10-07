// TODO: 轮廓线DP
/*
 * LCP 04. 覆盖
你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，你想把这些骨牌不重叠地覆盖在完好的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。



输入：n, m代表棋盘的大小；broken是一个b * 2的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。

输出：一个整数，代表最多能在棋盘上放的骨牌数。
*/

#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// 二分图, 匈牙利算法
class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
      vector<vector<bool> > valid(n, vector<bool>(m, true));
      vector<vector<bool> > vis(n, vector<bool>(m, false));
      for (auto &v : broken) {
        valid[v[0]][v[1]] = false;
      }
      // 按x + y的奇偶性分成两个子图
      vector<vector<pair<int, int> > > pairs(n, vector<pair<int, int> > (m, {-1, -1}));
      // 奇找偶, 由偶记录奇节点的坐标即可
      function<bool(int r, int c)> found = [&](int r, int c) -> bool {
        // r + c % 2 == 1
        for (auto [dr, dc] : DIRS) {
          unsigned int nr = dr + r;
          unsigned int nc = dc + c;
          if (nr < n && nc < m) {
            // 找不到应该找下一个, 而不是直接返回
            // 条件要写对!
            if (!valid[nr][nc] || vis[nr][nc]) continue;
            vis[nr][nc] = true;  // 尝试占有
            pair<int, int> &p = pairs[nr][nc];
            if (p.first == -1 || found(p.first, p.second)) {
              p = {r, c};
              return true;
            }
          }
        }
        return false;
      };
      int ans = 0;
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
          // 注意优先级, %的优先级比+高
          if ((r + c) % 2 == 1 && valid[r][c]) {
            set_false(vis);
            if (found(r, c)) ++ans;
          }
        }
      }
      return ans;
    }
    inline void set_false(vector<vector<bool> > &data) {
      for (auto &v : data) {
        v = vector<bool>(v.size(), false);
      }
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
      const int num_states = 1 << m;
      vector<vector<int> > dp(2, vector<int>(num_states));
      dp[0] = vector<int>(num_states, INT32_MIN);
      dp[0][num_states - 1] = 0;
      unordered_map<int, int> broken_r;
      for (auto v: broken) {
        broken_r[v[0]] |= 1 << v[1];
      }
      int last = 0, cur = 1;
      for (int r = 0; r < n; ++r) {
        // cout << "ROW: " << r << endl;
        int b = broken_r[r];
        // cout << "BLOCK: " << b << endl;
        // 枚举当前行的状态s
        for (int s = 0; s < num_states; ++s) {
          // 注意, 竖着的砖的行位置是r-1和r
          // cout << "s, b, s & b" << s << ", " << b << ", " << (s & b) << endl;
          // NOTICE: ==优先级更高!
          if ((s & b) == b) {
            int best = 0;
            // 去掉障碍物, 得到状态t, 尽可能放竖的
            int t = s & (~b);
            // 枚举上一行的状态
            for (int c = 0; c < num_states; ++c) {
              // 尽可能放竖的
              int vcount = count_bit1(t & (~c));
              int hrest = t & c;  // 剩下的可能能放横的
              int hcount = count_hbit2(hrest);
              int su = vcount + hcount + dp[last][c];
              // cout << "cur and last: " << s << ", " << c << " = " << su <<  "(" << vcount << ", " << hcount << ")" << hrest << endl;
              best = max(best, su);
            }
            dp[cur][s] = best;
          } else {
            // 不符合预期的都设为最小值
            dp[cur][s] = INT32_MIN;
          }
        }
        // PRINT_ARRAY(dp[cur]);
        last = cur;
        cur = 1 - cur;
      }
      int best = 0;
      for (int s = 0; s < num_states; ++s) {
        best = max(best, dp[last][s]);
      }
      return best;
    }
    int count_bit1(int u) {
      int count = 0;
      while (u > 0) {
        ++count;
        u &= u - 1;
      }
      return count;
    }
    int count_hbit2(int u) {
      int count = 0;
      while (u > 0) {
        int t = u & (-u);  // 得到最后一个1
        if (u & (t << 1)) ++count;
        u &= ~t;
        u &= ~(t << 1);
      }
      return count;
    }
};

#endif

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > broken;
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int r, c;
    cin >> r >> c;
    broken.push_back({r, c});
  }
  cout << Solution().domino(n, m, broken) << endl;
  return 0;
}
