#include "common.h"


const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const char dirc[4] = {'R', 'D', 'L', 'U'};

class Solution {
public:
    vector<string> printKMoves(int K) {
        if (K == 0) return {"R"};
        // 这里用map比unordered_map更快(200ms vs 252ms)
        map<pair<int, int>, char> ma;
        pair<int, int> pos{0, 0};
        int minr = 0, minc = 0;
        int maxr = 0, maxc = 0;
        int d = 0;
        for (int k = 0; k < K; ++k) {
            // 如果确实是白色, 那么反转颜色
            auto p = ma.insert({pos, 'X'});
            if (p.second || p.first->second == '_') {
                // 确实是白色
                d = (d + 1) % 4;
                p.first->second = 'X';
            } else {
                d = (d + 4 - 1) % 4;
                p.first->second = '_';
            }
            pos.first += dirs[d][0];
            pos.second += dirs[d][1];
            minr = min(pos.first, minr);
            minc = min(pos.second, minc);
            maxr = max(pos.first, maxr);
            maxc = max(pos.second, maxc);
        }
        ma[pos] = dirc[d];
        const int R = maxr - minr + 1;
        const int C = maxc - minc + 1;
        vector<string> res(R, string(C, '_'));
        // 直接遍历ma, 能从1912ms降到200ms
        for (auto &p : ma) {
            res[p.first.first - minr][p.first.second - minc] = p.second;
        }
        return res;
    }
};


int main() {
  int k; cin >> k;
  auto res = (Solution().printKMoves(k));
  for (auto v : res) {
    cout << v << endl;
  }
  return 0;
}
