#include "common.h"

#define SOLUTION 5

#if SOLUTION == 1
// 60 ms, 14 MB
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int n = M.size();
        vector<bool> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                ++cnt;
                queue<int> q;
                q.push(i);
                
                while (!q.empty()) {
                    int r = q.front(); q.pop();
                    for (int t = 0; t < n; ++t) {
                        if (M[r][t] && !vis[t]) {
                            vis[t] = true;
                            q.push(t);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
#elif SOLUTION == 2

// 732 ms, 13.7 MB
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
      const int n = M.size();
      if (n == 0) return 0;
      vector<vector<int> > H(n, vector<int>(n));
      using v2 = vector<vector<int>>;
      v2 *a = &M, *b = &H;
      while (1) {
        // b = a @ a
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            (*b)[i][j] = 0;
          }
        }
        for (int i = 0; i < n; ++i) {
          for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
              (*b)[i][j] |= (*a)[i][k] & (*a)[k][j];
            }
          }
        }
        bool eq = true;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if ((*a)[i][j] != (*b)[i][j]) {
              eq = false;
              break;
            }
          }
        }
        if (eq) break;
        swap(a, b);
      }
      vector<bool> vis(n, false);
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
          ++cnt;
          for (int j = 0; j < n; ++j) {
            if ((*a)[i][j]) vis[j] = true;
          }
        }
      }
      return cnt;
    }
};

#elif SOLUTION == 3


// 336 ms, 13.7 MB
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
      const int n = M.size();
      if (n == 0) return 0;

      bool changed = false;
      do {
        changed = false;
        for (int i = 0; i < n; ++i) {
          for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
              if (!M[i][j] && (M[i][k] & M[k][j])) {
                M[i][j] = true;
                changed = true;
              }
            }
          }
        }
      } while (changed);

      vector<bool> vis(n, false);
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
          ++cnt;
          for (int j = 0; j < n; ++j) {
            if (M[i][j]) vis[j] = true;
          }
        }
      }
      return cnt;
    }
};

#elif SOLUTION == 4

// 60 ms, 13.8 MB
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
      const int n = M.size();
      if (n == 0) return 0;
      vector<int> parents(n, -1);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (M[i][j]) {
            int pi = get_parent(parents, i);
            int pj = get_parent(parents, j);
            if (pi != pj)
              parents[pj] = pi;
          }
        }
      }
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (parents[i] == -1) ++cnt;
      }
      return cnt;
    }
    int get_parent(vector<int> &parents, int i) {
      if (parents[i] == -1) return i; 
      return parents[i] = get_parent(parents, parents[i]);
    }
};

#elif SOLUTION == 5

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
      const int n = M.size();
      if (n == 0) return 0;
      vector<int> parents(n);
      iota(parents.begin(), parents.end(), 0);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (M[i][j]) {
            int pi = get_parent(parents, i);
            int pj = get_parent(parents, j);
            parents[pj] = pi;
          }
        }
      }
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (parents[i] == i) ++cnt;
      }
      return cnt;
    }
    int get_parent(vector<int> &parents, int i) {
      if (parents[i] == i) return i; 
      return parents[i] = get_parent(parents, parents[i]);
    }
};


#endif

int main() {
  vector<vector<int> > M;
  INPUT_ARRAY2D(M);
  cout << Solution().findCircleNum(M) << endl;
  return 0;
}
