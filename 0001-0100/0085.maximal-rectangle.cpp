// TODO: 好好理解柱状图的最大矩形
#include "common.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return 0;
        const int cols = matrix[0].size();
        if (cols == 0) return 0;
        // 先列后行
        vector<vector<int> > left(cols, vector<int>(rows, 0));
        for (int r = 0; r < rows; ++r) {
          left[0][r] = matrix[r][0] == '1';
          for (int c = 1; c < cols; ++c) {
            if (matrix[r][c] == '1') {
              left[c][r] = left[c - 1][r] + 1;
            }
          }
        }
        int ans = 0;
        for (int c = 0; c < cols; ++c) {
          ans = max(ans, largestRectangleArea(left[c]));
        }
        return ans;
    }
    // https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
    int largestRectangleArea(vector<int>& heights) {
        const int len = heights.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i <= len; ++i) {
            int h = i < len ? heights[i] : 0;
            while (st.top() != -1 && h < heights[st.top()]) {
                int r = heights[st.top()]; st.pop();
                int w = i - st.top() - 1;
                ans = max(ans, w * r);
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
  // vector<vector<char> > matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  vector<vector<char> > matrix = {{'1', '0'}};
  Solution sol;
  cout << sol.maximalRectangle(matrix) << endl;

  return 0;
}
