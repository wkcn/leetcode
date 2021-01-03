#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按左端点排序，在比较时，移除相邻且右端点更右的
        // 和戳气球的题目类似: 452: minimum-number-of-arrows-to-burst-balloons
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        int ans = 0;
        int i = 0, j;
        while (i < intervals.size()) {
            int right = intervals[i][1];
            for (j = i + 1; j < intervals.size(); ++j) {
                if (right > intervals[j][0]) {
                    // 有重叠, 移除右端最右的
                    right = min(right, intervals[j][1]);
                    ++ans;
                } else break;
            }
            i = j;
        }
        return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按左端点排序，在比较时，移除相邻且右端点更右的
        // 和戳气球的题目类似: 452: minimum-number-of-arrows-to-burst-balloons
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int i = 0, j;
        while (i < intervals.size()) {
          int right = intervals[i][1];
          for (j = i + 1; j < intervals.size(); ++j) {
            if (intervals[j][0] < right) {
              ++ans;
            } else break;
          }
          i = j;
        }
        return ans;
    }
};

#endif

int main() {
  {
    vector<vector<int> > t = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << Solution().eraseOverlapIntervals(t) << endl;
  }
  {
    vector<vector<int> > t = {{1, 2}, {1, 2}, {1, 2}};
    cout << Solution().eraseOverlapIntervals(t) << endl;
  }
  {
    vector<vector<int> > t = {{1, 2}, {2, 3}};
    cout << Solution().eraseOverlapIntervals(t) << endl;
  }
  return 0;
}
