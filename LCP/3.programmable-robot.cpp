/*
LCP 03. 机器人大冒险
力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

U: 向y轴正方向移动一格
R: 向x轴正方向移动一格。
不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。
*/
#include "common.h"

struct pair_hash {
  inline size_t operator()(const pair<int, int> &p) const {
    return (((size_t)p.first) << (sizeof(int) * 8)) | p.second;
  }
};

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
      /*
       * URR:
       * (0, 0), (0, 1), (1, 1),
       * (2, 1), (2, 2), (3, 2),
       * (4, 2)
       *   
       */
      unordered_set<pair<int, int>, pair_hash> obs;
      obs.insert({0, 0});
      int nx = 0, ny = 0;
      for (char c : command) {
        if (c == 'U') ++ny;
        else ++nx;
        obs.insert({nx, ny});
      }
      // 判断路径上没有障碍物
      for (auto &v : obstacles) {
        if (v[0] > x || v[1] > y) continue;
        int T = min(v[0] / nx, v[1] / ny);
        if (obs.count({v[0] - nx * T, v[1] - ny * T})) {
          return false;
        }
      }
      int T = min(x / nx, y / ny);
      return obs.count({x - nx * T, y - ny * T});
    }
};

int main() {
  string command;
  int x, y;
  cin >> command;
  int n;
  cin >> n;
  vector<vector<int>> obstacles(n);
  for (int i = 0; i < n; ++i) {
    int tx, ty;
    cin >> tx >> ty;
    obstacles[i] = {tx, ty}; 
  }
  cin >> x >> y;
  cout << Solution().robot(command, obstacles, x, y) << endl;
  return 0;
}
