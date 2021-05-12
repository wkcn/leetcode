#include "common.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      vector<int> prexor(arr.size() + 1);
      prexor[0] = 0;
      for (int i = 0; i < arr.size(); ++i) {
        prexor[i + 1] = arr[i] ^ prexor[i];
      }
      vector<int> ans(queries.size());
      for (int i = 0; i < queries.size(); ++i) {
        int left = queries[i][0];
        int right = queries[i][1];
        // [left, right] = [left, right + 1)
        ans[i] = prexor[left] ^ prexor[right + 1]; 
      }
      return ans;
    }
};

int main() {
  vector<int> arr{1, 3, 4, 8};
  vector<vector<int>> queries{{0, 1}, {1, 2}, {0, 3}, {3, 3}};
  PRINT_ARRAY(Solution().xorQueries(arr, queries));
  return 0;
}
