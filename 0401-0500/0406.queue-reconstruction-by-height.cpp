#include "common.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int n = people.size();
        if (n == 0) return {};
        // 先排低的
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
          if (a[0] != b[0]) return a[0] < b[0];
          return a[1] > b[1];
        });
        vector<vector<int> > ans(n);
        for (vector<int> &v : people) {
          int k = v[1];
          for (int i = 0; i < n; ++i) {
            if (ans[i].empty()) {
              if (k-- == 0) {
                ans[i] = std::move(v);
                break;
              }
            }
          }
        }
        return ans;
    }
};

int main() {
  vector<vector<int> > people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  PRINT_ARRAY2D(Solution().reconstructQueue(people));
  return 0;
}
