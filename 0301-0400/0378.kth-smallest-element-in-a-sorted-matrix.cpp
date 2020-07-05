#include "common.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int rows = matrix.size();
        if (rows == 0) return 0;
        const int cols = matrix[0].size();
        if (cols == 0) return 0;
        int lo = matrix[0][0], hi = matrix[rows-1][cols-1] + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            // count left (<= mid)
            int count = 0;
            int r = 0, c = cols-1;
            while (r < rows && c >= 0) {
                while (c >= 0 && matrix[r][c] > mid) --c;
                if (c < 0) break;
                count += c + 1;
                ++r;
            }
            count < k ? lo = mid + 1 : hi = mid;
        }
        return lo;
    }
};

int main() {
  vector<vector<int> > matrix; int k;
  INPUT_ARRAY2D(matrix); cin >> k;
  cout << Solution().kthSmallest(matrix, k) << endl;
  return 0;
}
