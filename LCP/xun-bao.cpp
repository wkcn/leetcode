#include "common.h"

class Solution {
public:
    int minimalSteps(vector<string>& maze) {
      // 开始 S
      // 墙壁 #
      // 石堆 O
      // 机关 M
      // 空闲 .
      // 宝藏 T
      /*
       * S -> O -> M -> O -> M -> ... -> O -> M -> T
       * namely S -> (O -> M) * k -> T
       */
      const int rows = maze.size();
      if (rows == 0) return 0;
      const int cols = maze[0].size();
      if (cols == 0) return 0;
      // step 1: 对机关、石头进行编码
      vector<pair<int, int> > M;
      vector<pair<int, int> > O;
      pair<int, int> spos{-1, -1}, tpos{-1, -1};
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          switch (maze[r][c]) {
            case 'M':
              M.push_back({r, c});
              break;
            case 'O':
              O.push_back({r, c});
              break;
            case 'S':
              spos = {r, c};
              break;
            case 'T':
              tpos = {r, c};
              break;
          };
        }
      }

      // step 2: 计算起点是否能到终点 
      const auto start_from_spos = bfs(maze, spos);
      {
        int dis = start_from_spos[tpos.first][tpos.second];
        if (dis == INT32_MAX) return -1;
        if (M.empty()) {
          return dis;
        }
      }

      // step 3: 计算从终点出发
      const auto start_from_tpos = bfs(maze, tpos);

      // step 4: 计算从机关出发 
      vector<vector<vector<int> > > start_from_machs(M.size());
      for (int i = 0; i < M.size(); ++i) {
        start_from_machs[i] = bfs(maze, M[i]);
      }

      // step 5: 计算机关到机关之间(中间是石头)的距离
      vector<vector<int> > M_dis(M.size(), vector<int>(M.size()));
      for (int i = 0; i < M.size(); ++i) {
        M_dis[i][i] = 0;
        for (int j = i + 1; j < M.size(); ++j) {
          int dis = INT32_MAX;
          // 枚举石头位置
          for (auto &s : O) {
            int dis1 = start_from_machs[i][s.first][s.second];
            if (dis1 == INT32_MAX) continue;
            int dis2 = start_from_machs[j][s.first][s.second];
            if (dis2 == INT32_MAX) continue;
            dis = min(dis, dis1 + dis2);
          }
          if (dis == INT32_MAX) return -1;
          M_dis[i][j] = M_dis[j][i] = dis;
        }
      }

      // step 6: 状态压缩
      // [0, (1 << M.size()) - 1]
      const int num_states = 1 << M.size();
      // dp[机关按压状态][最后结束的机关id]
      vector<vector<int> > dp(num_states, vector<int>(M.size(), INT32_MAX));
      dp[0] = vector<int>(M.size(), 0);
      // 初始化：从起点到第一个石头再到第一个机关
      for (int i = 0; i < M.size(); ++i) {
          int dis = INT32_MAX;
          for (auto &s : O) {
            int dis1 = start_from_spos[s.first][s.second];
            if (dis1 == INT32_MAX) continue;
            int dis2 = start_from_machs[i][s.first][s.second];
            if (dis2 == INT32_MAX) continue;
            dis = min(dis, dis1 + dis2);
          }
          if (dis == INT32_MAX) return -1;
          dp[1 << i][i] = dis;
      }
      // 从第一个机关到最后一个机关
      for (int i = 1; i < num_states; ++i) {
        for (int j = 0; j < M.size(); ++j) {
          // 从dp[i][j]出发开始构造
          if (dp[i][j] == INT32_MAX) continue;
          for (int k = 0; k < M.size(); ++k) {
            // k是指下一个机关
            int next = (1 << k) | i;
            if (next == i) continue; // 已经按压
            dp[next][k] = min(dp[next][k], dp[i][j] + M_dis[j][k]); 
          }
        }
      }

      auto &fronts = dp[num_states - 1];

      // step 7: 计算最后一个机关到终点的距离
      int best = INT32_MAX;
      for (int i = 0; i < M.size(); ++i) {
        best = min(best, fronts[i] + start_from_tpos[M[i].first][M[i].second]);
      }
      return best == INT32_MAX ? -1 : best; 
    }
    vector<vector<int> > bfs(const vector<string> &maze,
        pair<int, int> source) {
      const int rows = maze.size();
      const int cols = maze[0].size();
      vector<vector<int> > buf(rows, vector<int>(cols, INT32_MAX));
      queue<pair<int, int> > q;
      q.push(source);
      buf[source.first][source.second] = 0;
      int step = 1;
      while (!q.empty()) {
        int size = q.size();
        while (size--) {
          auto p = q.front(); q.pop();
          for (const auto &d : dirs) {
            unsigned int nr = p.first + d[0];
            unsigned int nc = p.second + d[1];
            if (nr < rows && nc < cols && buf[nr][nc] == INT32_MAX) {
              if (maze[nr][nc] != '#') {
                buf[nr][nc] = step;
                q.push({nr, nc});
              } 
            }
          }
        }
        ++step;
      }
      return buf;
    }
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main() {
  auto vs = std::vector<string>{"S#O", "M..", "M.T"};
  cout << Solution().minimalSteps(vs) << endl;  // 16
  return 0;
}
