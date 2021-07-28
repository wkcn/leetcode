#include "common.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      // buildings is sorted by x
      unordered_set<int> se;
      for (auto &v : buildings) {
        se.insert(v[0]);
        se.insert(v[1]);
      }
      vector<int> xs(se.begin(), se.end()); sort(xs.begin(), xs.end());

      vector<vector<int>> ans;

      priority_queue<pair<int, int>> pq;  // [(height, right_x)]
      int i = 0;
      int last_height = 0;
      for (int x : xs) {
        while (i < buildings.size() && x >= buildings[i][0]) {
          pq.push({buildings[i][2], buildings[i][1]});
          ++i;
        }
        // 注意这里的等号
        while (!pq.empty() && x >= pq.top().second) {
          pq.pop();
        }
        // pq may be empty
        int ch = pq.empty() ? 0 : pq.top().first;
        if (ch != last_height) {
          ans.push_back({x, ch});
          last_height = ch;
        }
      } 
      return ans;
    }
};

int main() {
  vector<vector<int>> buildings{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
  PRINT_ARRAY2D(Solution().getSkyline(buildings));
  return 0;
}
