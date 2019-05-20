#include "common.h"

int dirxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      for (auto &p : obstacles) {
        is_obs.insert({p[0], p[1]});
      }
      int x = 0, y = 0, dir = 0;
      int max_dis = 0;
      for (int c : commands) {
        switch (c) {
          case -2:
            dir = (dir - 1 + 4) % 4;
            break;
          case -1:
            dir = (dir + 1) % 4;
            break;
          default:
            for (int i = 0; i < c; ++i) {
              int nx = x + dirxy[dir][0];
              int ny = y + dirxy[dir][1];
              bool fail = false;
              if (is_obs.count({nx, ny}) == 0) {
                x = nx, y = ny;
                max_dis = max(max_dis, x * x + y * y);
              }
            }
        };
      }
      return max_dis; 
    }
private:
    set<pair<int, int> > is_obs;
};

int main() {
  vector<int> commands;
  INPUT_ARRAY(commands);
  vector<vector<int> > obs;
  INPUT_ARRAY2D(obs);
  cout << Solution().robotSim(commands, obs) << endl;
  return 0;
}
