#if SOLUTION == 1
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    const int n = matrix.size();
    /*
     * 1 2 3
     * 4 5 6
     * 7 8 9
     * 
     * 1 2 3 4
     * 5 6 7 8
     * 9 0 1 2
     * 3 4 5 6
     */
    for (int i = 0; i < n / 2; ++i) {
      for (int j = i; j < n - i - 1; ++j) {
        /*
         * (i, j) -> (j, n-1-i) -> (n-1-i, n-1-j) -> (n-1-j, i)
         */
        // A -> B -> C -> D
        // D -> A -> B -> C
        myswap(matrix[i][j], matrix[n-1-j][i]); // D -> B -> C -> A
        myswap(matrix[j][n-1-i], matrix[n-1-j][i]); // D -> A -> C -> B
        myswap(matrix[n-1-i][n-1-j], matrix[n-1-j][i]);
      }
    }
  }
  void myswap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }
};
#elif SOLUTION == 2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n == 0) return;
        int t = n - 1;
        int r = 0;
        while (t > 0) {
            for (int c = r; c < r + t; ++c) {
                int &a1 = matrix[r][c];
                int &a2 = matrix[c][n-1-r];
                int &a3 = matrix[n-1-r][n-1-c];
                int &a4 = matrix[n-1-c][r];
                // 1234 -> 4123
                my_swap(a1, a4); // 4231
                my_swap(a2, a4); // 4132
                my_swap(a3, a4);
            }
            t -= 2;
            ++r;
        }
    }
    inline void my_swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};
#elif SOLUTION == 3
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n == 0) return;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < r; ++c) {
                my_swap(matrix[r][c], matrix[c][r]);
            }
        }
        const int half = n / 2;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < half; ++c) {
                my_swap(matrix[r][c], matrix[r][n-1-c]);
            }
        }
    }
    inline void my_swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};
#endif
