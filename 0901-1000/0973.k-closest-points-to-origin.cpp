#include "common.h"

template <typename ITER, typename COMPARE>
void my_nth_element(ITER begin, ITER mid, ITER end, COMPARE comp) {
    queue<pair<ITER, ITER> > q;
    q.push({begin, end});
    while (!q.empty()) {
        auto [left, right] = q.front(); q.pop();
        if (distance(left, right) <= 1) continue;
        auto val = *left;
        ITER i = left, j = prev(right);
        while (i < j) {
            while (i < j && !comp(*j, val)) --j;
            // 注意是谁覆盖谁!!!!
            *i = *j;
            while (i < j && !comp(val, *i)) ++i;
            *j = *i;
        }
        *j = val;
        if (i < mid) {
            q.push({i + 1, right});
        } else if (i > mid) {
            q.push({left, i});
        }
    }
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (K == 0) return {};
        if (points.size() <= K) return points;
        const int len = points.size();
        vector<int> inds(len);
        iota(inds.begin(), inds.end(), 0);
        vector<int> dis(len);
        for (int i = 0; i < len; ++i) {
            dis[i] = points[i][0] * points[i][0] + \
                     points[i][1] * points[i][1];
        }
        my_nth_element(inds.begin(), inds.begin() + K, inds.end(), [&](int i, int j) {
            return dis[i] < dis[j];
        });
        vector<vector<int> > out(K);
        for (int k = 0; k < K; ++k) {
            out[k] = points[inds[k]];
        }
        return out;
    }
};

int main() {
  vector<vector<int> > points = {{1, 3}, {-2, 2}};
  int K = 1;
  auto res = Solution().kClosest(points, K);
  PRINT_ARRAY2D(res);
  return 0;
}
