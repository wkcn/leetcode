/*
 *Runtime: 20 ms, faster than 100.00% of C++ online submissions for Course Schedule.
  Memory Usage: 11.7 MB, less than 80.11% of C++ online submissions for Course Schedule.
 */

#include "common.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<vector<int> > ves(numCourses);
      vector<int> indegrees(numCourses);
      queue<int> qu;
      for (auto &p : prerequisites) {
        ves[p.second].push_back(p.first);
        ++indegrees[p.first];
      }
      for (int i = 0; i < numCourses; ++i) {
        if (indegrees[i] == 0) {
          qu.push(i);
        }
      }
      int count = qu.size();
      while (!qu.empty()) {
        int t = qu.front(); qu.pop();
        for (int &y : ves[t]) {
          if (--indegrees[y] == 0) {
            qu.push(y);
            ++count;
          }
        }
      }
      return count == numCourses;
    }
};

int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<pair<int, int> > pres;
  while (m--) {
    int a, b;
    cin >> a >> b;
    pres.push_back({a, b});
  }
  Solution so;
  cout << so.canFinish(n, pres) << endl;
  return 0;
}
