#include "common.h"

#define SOLUTION 1

#if SOLUTION == 0
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
  bool hasPath(char* matrix, int rows, int cols, char* str) {
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (find_from_pos(matrix, rows, cols, str, r, c)) return true;
      }
    }
    return false;
  }
private:
  bool find_from_pos(char* matrix, int rows, int cols, char* str, int r, int c) {
    if (matrix[cols * r + c] != str[0]) return false;
    stack<pair<int, int> > st;
    stack<int> dir_st;
    vector<vector<bool> > vis(rows, vector<bool>(cols, false));
    vis[r][c] = true;
    int i = 1;
    st.push({r, c});
    dir_st.push(0);
    while (str[i] && !st.empty()) {
      pair<int, int> p = st.top();
      int d = dir_st.top(); dir_st.pop();
      if (d < 4) {
        // update d
        dir_st.push(d + 1);
        int nr = p.first + dir[d][0];
        int nc = p.second + dir[d][1];
        if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
          if (!vis[nr][nc] && matrix[cols * nr + nc] == str[i]) {
            vis[nr][nc] = true;
            ++i;
            st.push({nr, nc});
            dir_st.push(0);
          }
        }
      } else {
        vis[p.first][p.second] = false;
        --i;
        st.pop();
      }
    }
    return !str[i];
  }
};
#elif SOLUTION == 1

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
  bool hasPath(char* matrix, int rows, int cols, char* str) {
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        vector<vector<bool> > vis(rows, vector<bool>(cols, false));
        if (find_from_pos(matrix, rows, cols, str, r, c, vis)) return true;
      }
    }
    return false;
  }
private:
  bool find_from_pos(char* matrix, int rows, int cols, char* str, int r, int c, vector<vector<bool> > &vis) {
    if (!str[0]) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (vis[r][c]) return false;
    vis[r][c] = true;
    if (matrix[r * cols + c] == str[0]) {
      for (int d = 0; d < 4; ++d) {
        if (find_from_pos(matrix, rows, cols, str+1, r + dir[d][0], c + dir[d][1], vis)) {
          return true;
        }
      }
    }
    vis[r][c] = false;
    return false;
  }
};

#endif

int main() {
  /*
   *
     3 4
     a b c e
     s f c s
     a d e e
     bcced
   */
  vector<vector<char> > mat;
  INPUT_ARRAY2D(mat);
  int rows = mat.size();
  int cols = mat[0].size();
  char* p = new char[rows*cols];
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      p[r * cols + c] = mat[r][c];
    }
  }
  string s;
  cin >> s;
  cout << Solution().hasPath(p, rows, cols, const_cast<char*>(s.c_str())) << endl;
  return 0;
}
