#include "common.h"

#if 0
/*
 * 运行时间：9ms
 * 占用内存：1500k
 */
struct Pos {
  int r1, c1, r2, c2;
};
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if (row == 0) return false;
        int col = array[0].size();
        if (col == 0) return false;
        // (r1, c1) -> (r2, c2)
        queue<Pos> q;
        q.push({0, 0, row, col});
        while (!q.empty()) {
          Pos p = q.front(); q.pop();
          int r1 = p.r1;
          int c1 = p.c1;
          int r2 = p.r2;
          int c2 = p.c2;
          if (r1 >= r2 || c1 >= c2) continue;
          int r_mid = r1 + (r2 - r1) / 2;
          int c_mid = c1 + (c2 - c1) / 2;
          int val = array[r_mid][c_mid];
          if (target == val) return true;
          if (target < val) {
            q.push({r1, c1, r_mid, c_mid});
            q.push({r1, c_mid, r_mid, c2});
            q.push({r_mid, c1, r2, c_mid});
          } else {
            q.push({r_mid+1, c_mid+1, r2, c2});
            q.push({r1, c_mid+1, r_mid+1, c2});
            q.push({r_mid+1, c1, r2, c_mid+1});
          }
        }
        return false;
    }
};
#else

/*
 * 运行时间：13ms
 * 占用内存：1476k
 */
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if (row == 0) return false;
        int col = array[0].size();
        if (col == 0) return false;
        // right top
        int r = 0;
        int c = col - 1;
        while (r < row && c >= 0) {
          int val = array[r][c];
          if (val == target) return true;
          if (val < target) {
            ++r;
          } else {
            --c;
          }
        }
        return false;
    }
};

#endif

int main() {
  int target; cin >> target;
  vector<vector<int> > array;
  INPUT_ARRAY2D<int>(array);
  cout << Solution().Find(target, array) << endl;
  return 0;
}
