#include "common.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
      const int R = matrix.size();
      const int C = matrix[0].size();

      vector<int> rs(R), cs(matrix[0]); 
      for (int r = 0; r < R; ++r) rs[r] = matrix[r][0];

      for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
          rs[r] = min(rs[r], matrix[r][c]);
          cs[c] = max(cs[c], matrix[r][c]);
        }
      }

      vector<int> ans;
      for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
          if (matrix[r][c] == rs[r] && rs[r] == cs[c]) {
            ans.push_back(matrix[r][c]);
          }
        }
      }
      return ans;
    }
};

int main() {
  vector<vector<int>> matrix{{3,7,8},{9,11,13},{15,16,17}};
  PRINT_ARRAY(Solution().luckyNumbers(matrix));
  return 0;
}
