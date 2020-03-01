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
