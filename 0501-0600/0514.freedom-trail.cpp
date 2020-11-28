#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int rlen = ring.size();
        array<vector<int>, 26> ma;
        for (int i = 0; i < ring.size(); ++i) {
            ma[ring[i] - 'a'].push_back(i);
        }
        queue<pair<int, int> > q; // (当前id, 计数)
        q.push({0, 0});
        for (char c : key) {
            int qsize = q.size();
            vector<int> &vc = ma[c - 'a'];
            unordered_map<int, int> ma; // 新位置id, 计数. 避免同样id的元素出现多次
            while (qsize--) {
                auto [id, cnt] = q.front(); q.pop();
                for (int t : vc) {
                    int r = abs(t - id);
                    int step = min(r, rlen - r) + 1 + cnt;
                    auto y = ma.insert({t, step});
                    if (!y.second) {
                        y.first->second = min(y.first->second, step);
                    }
                }
            }
            for (auto &p : ma) {
                q.push(move(p));
            }
        }
        int best = INT32_MAX;
        while (!q.empty()) {
            auto [id, cnt] = q.front(); q.pop();
            best = min(best, cnt);
        }
        return best;
    }
};

#elif SOLUTION == 2

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int rlen = ring.size();
        array<vector<int>, 26> ma;
        for (int i = 0; i < ring.size(); ++i) {
            ma[ring[i] - 'a'].push_back(i);
        }
        int dp[2][100];
        for (int k = 0; k < rlen; ++k) {
          dp[0][k] = INT32_MAX;
        }
        // 变量要写对!
        for (int t : ma[key[0] - 'a']) {
          dp[0][t] = min(t, rlen - t) + 1;
        }
        int cur = 0;
        for (int i = 1; i < key.size(); ++i) {
          const int nex = cur ^ 1;
          for (int k = 0; k < rlen; ++k) {
            dp[nex][k] = INT32_MAX;
          }
          // cout << "==========" << key[i] << endl;
          // 注意哪里要减'a', 哪里不需要
          for (int t : ma[key[i] - 'a']) {
            for (int f : ma[key[i-1] - 'a']) {
              // assert(dp[cur][f] < INT32_MAX);
              int d = abs(t - f);
              int step = min(d, rlen - d) + 1;
              // cout << "from " << key[i-1] << f << " to " << key[i] << t << " | " << step << " + " << dp[cur][f] << endl;
              // 注意min的两个参数, 其中一个是旧参数
              dp[nex][t] = min(dp[nex][t], step + dp[cur][f]);
            }
          }
          cur = nex;
        }
        return *min_element(dp[cur], dp[cur] + rlen);
    }
};

#endif

int main() {
  //string ring = "godding";
  //string key = "gd";
  // string key = "godding";
  string ring = "edcba";
  string key = "abcde";
  cout << Solution().findRotateSteps(ring, key) << endl;
  return 0;
}
