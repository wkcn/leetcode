#include "common.h"

// 计算三元组的哈希值
struct v3_hash {
  size_t operator()(const array<int, 3> &x) const {
    return x[0] ^ x[1] ^ ((size_t)x[2] << 32);
  }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      // Ax + By + C = 0, (A, B, C)
      // A(x1 - x2) + B(y1 - y2) = 0
      // (A, B, C) = (y2 - y1, x1 - x2, x2 * y1 - x1 * y2)
      int best = 0;
      for (int i = 0; i < points.size(); ++i) {
        // 记录同一条直线的出现次数
        unordered_map<array<int, 3>, int, v3_hash> cnts;
        const int x1 = points[i][0];
        const int y1 = points[i][1];
        for (int j = i + 1; j < points.size(); ++j) {
          const int x2 = points[j][0];
          const int y2 = points[j][1];
          // 计算表示一条直线的三元组
          array<int, 3> v3 = {y2 - y1, x1 - x2, x2 * y1 - x1 * y2};
          bool first_non_zero = true;  // 判断是否遇到第一个非零元素
          bool minus = false;  // 记录三元组第一个非零元素是否为负数
          int g = 0;  // 变量g记录最大公约数
          for (int k = 0; k < 3; ++k) {
            if (v3[k] != 0) {
              if (first_non_zero) {
                first_non_zero = false;
                minus = v3[k] < 0;
                g = abs(v3[k]);
              } else {
                g = __gcd(g, abs(v3[k]));
              }
            }
          }
          // 对三元组进行约分
          if (g != 0) {
            if (minus) g = -g;
            for (int k = 0; k < 3; ++k) {
              if (v3[k] != 0) v3[k] /= g;
            }
          }
          best = max(best, ++cnts[v3]);
        }
      }
      // 直线上最多的点数 = 同一条直线出现的最大次数 + 1
      return best + 1;
    }
};

int main() {
  {
    vector<vector<int>> points{{1, 1}, {2, 2}, {3, 3}};
    cout << Solution().maxPoints(points) << endl;
  }

  {
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << Solution().maxPoints(points) << endl;
  }
  return 0;
}
