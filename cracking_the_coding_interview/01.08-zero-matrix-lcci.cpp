// vector<bool> v 是特化版本, sizeof(v[0]) = 16, 不要直接用来做位运算！
// https://www.cnblogs.com/wpcockroach/p/3179572.html
// https://www.zhihu.com/question/23367698
// 可以只用第一行（列0上移）和一个bool实现
// 
// 0很稀疏，可以用一个数组来记录0的位置
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      const int row = matrix.size();
      if (row == 0) return;
      const int col = matrix[0].size();
      if (col == 0) return;
      vector<bool> rowb(row, false), colb(col, false);
      for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          if (matrix[r][c] == 0) {
            rowb[r] = true;
            colb[c] = true;
          }
        }
      }
      for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          if (rowb[r] || colb[c]) {
            matrix[r][c] = 0;
          }
        }
      }
    }
};
#elif SOLUTION == 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      const int row = matrix.size();
      if (row == 0) return;
      const int col = matrix[0].size();
      if (col == 0) return;

      // 检查第一行是否有0
      bool del_first_row = false;
      for (int c = 0; c < col; ++c) {
        if (matrix[0][c] == 0) {
          del_first_row = true;
          break;
        }
      }

      for (int r = 1; r < row; ++r) {
        bool zero = false;
        for (int c = 0; c < col; ++c) {
          if (matrix[r][c] == 0) {
            matrix[0][c] = 0;
            zero = true;
            // 这里不应该break, 因为可能还有其他列为0！！！
          }
        }
        if (zero) {
          for (int c = 0; c < col; ++c) {
            matrix[r][c] = 0;
          }
        }
      }

      for (int c = 0; c < col; ++c) {
        if (matrix[0][c] == 0) {
          for (int r = 1; r < row; ++r) {
            matrix[r][c] = 0;
          }
        }
      }
      if (del_first_row) {
        for (int c = 0; c < col; ++c) matrix[0][c] = 0; 
      }
    }
};

#endif

int main() {
  cout << sizeof(bool) << endl;
  int three = 3;
  cout << HEX2STR(three) << endl;
  vector<bool> v = {false, true};
  cout << sizeof(v[0]) << endl;
  cout << HEX2STR(v[0]) << ", " << HEX2STR(v[1]) << endl;
  cout << HEX2STR(bool(v[0])) << ", " << HEX2STR(bool(v[1])) << endl;
  bool b2[2] = {false, true};
  cout << HEX2STR(b2[0]) << ", " << HEX2STR(b2[1]) << endl;

  vector<vector<int> > matrix;
  INPUT_ARRAY2D(matrix);
  Solution().setZeroes(matrix);
  PRINT_MATRIX(matrix);
  return 0;
}
