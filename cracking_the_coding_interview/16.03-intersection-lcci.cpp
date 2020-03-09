// 两线段交点 [HARD]
#include "common.h"

// TODO: 向量方法
// Reference: https://leetcode-cn.com/problems/intersection-lcci/solution/yi-ban-shi-qiu-jiao-dian-by-suibianfahui/
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
      int A1, B1, C1;
      int A2, B2, C2;
      // Ax + By + C = 0
      ComputeABC(start1, end1, A1, B1, C1);
      ComputeABC(start2, end2, A2, B2, C2);
      int D = A1 * B2 - A2 * B1;
      int E = B1 * C2 - B2 * C1;
      if (D == 0) {
        // 平行，需要判断是否共线
        if (E == 0) {
          // 共线
          vector<int> ans;
          bool found = false;
          for (const vector<int> &v : {start1, end1, start2, end2}) {
            if (InLine(v, start1, end1, start2, end2))
              if (!found || v[0] < ans[0] || (v[0] == ans[0] && v[1] < ans[1])) {
                ans = v;
                found = true;
              }
          }
          if (found) return {double(ans[0]), double(ans[1])};
          else return {};
        } else return {};
      } else {
        // 不平行
        int F = A2 * C1 - A1 * C2;
        vector<double> ans = {double(E) / D, double(F) / D};
        if (InLine(ans, start1, end1, start2, end2)) return ans;
      }
      return {};
    }
    void ComputeABC(vector<int> &start, vector<int> &end, int &A, int &B, int &C) {
      A = end[1] - start[1];
      B = start[0] - end[0];
      C = start[1] * end[0] - start[0] * end[1];
    }
    template <typename T>
    bool InLine(const vector<T> &pos,
        const vector<int>& start1, const vector<int>& end1,
        const vector<int>& start2, const vector<int>& end2) { 
      return InLine(pos, start1, end1) && InLine(pos, start2, end2);
    }
    template <typename T>
    bool InLine(const vector<T> &pos,
        const vector<int>& start,
        const vector<int>& end) { 
      int min_x = min(start[0], end[0]);
      int max_x = max(start[0], end[0]);
      int min_y = min(start[1], end[1]);
      int max_y = max(start[1], end[1]);
      return pos[0] >= min_x && pos[0] <= max_x && pos[1] >= min_y && pos[1] <= max_y;
    }
};

void INPUT_POS(vector<int> &p) {
  p.resize(2);
  cin >> p[0] >> p[1];
}

int main() {
  vector<int> start1, end1, start2, end2;
  INPUT_POS(start1);
  INPUT_POS(end1);
  INPUT_POS(start2);
  INPUT_POS(end2);
  PRINT_ARRAY(Solution().intersection(start1, end1, start2, end2));
  return 0;
}
