#include "common.h"

// TODO: BFPRT O(n)
//
// 这种实现会超时
int get_kth(vector<int> &data, int k) {
  int left = 0, right = data.size() - 1;
  // [left, right]
  while (left < right) {
    int lo = left, hi = right;
    // 随机划分, 避免出现1与n-1的情况
    swap(data[lo], data[rand() % (hi - lo + 1) + lo]);
    int pv = data[lo];
    while (lo < hi) {
      while (lo < hi  && pv <= data[hi]) --hi;
      // 不要改变lo和hi
      data[lo] = data[hi]; 
      while (lo < hi && pv >= data[lo]) ++lo;
      data[hi] = data[lo];
    }
    data[lo] = pv;
    if (lo < k) {
      left = lo + 1;
    } else if (lo == k) {
      return data[k];
    } else {
      // lo > k
      right = lo - 1;
    }
  }
  // 如果大循环的判断条件里没有=, 可能遇到left = right = k的情况, 因此要返回data[left]
  return data[left];
}


class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
      vector<int> data = get_data(matrix);
      nth_element(data.begin(), data.begin() + k - 1, data.end(), greater<int>());
      return data[k - 1];
      /*
      int v = get_kth(data, data.size() - k);
      return v;
      // naive
      sort(data.begin(), data.end(), greater<int>());
      return data[k - 1];
      */
    }
    vector<int> get_data(vector<vector<int>>& matrix) {
      const int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> out(m, vector<int>(n));
      out[0][0] = matrix[0][0];
      for (int r = 1; r < m; ++r) {
        out[r][0] = out[r-1][0] ^ matrix[r][0];
      }
      for (int c = 1; c < n; ++c) {
        out[0][c] = out[0][c-1] ^ matrix[0][c];
      }
      for (int r = 1; r < m; ++r) {
        for (int c = 1; c < n; ++c) {
          out[r][c] = matrix[r][c] ^ out[r-1][c] ^ out[r][c-1] ^ out[r-1][c-1];
        }
      }
      vector<int> ans(m * n);
      int t = 0;
      for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
          ans[t++] = out[r][c];
        }
      }
      return ans;
    }
};

int main() {
  vector<vector<int>> matrix{{5, 2}, {1, 6}};
  if (0) {
    int k = 1;
    cout << Solution().kthLargestValue(matrix, k) << endl;
  }
  if (0) {
    int k = 2;
    cout << Solution().kthLargestValue(matrix, k) << endl;
  }
  {
    int k = 3;
    cout << Solution().kthLargestValue(matrix, k) << endl;
  }
  return 0;
}
