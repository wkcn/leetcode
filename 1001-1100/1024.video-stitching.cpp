// TODO: 1. DP
//       2. 题解的贪心
#include "common.h"

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // 用数组记录, 使用i个片段最长能延长到哪个时间点
        // rec是递增数组
        vector<int> rec;
        rec.push_back(-1);
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int best = -1;
        int i = 0;
        for (; i < clips.size(); ++i) {
            if (clips[i][0] == 0) {
                best = max(clips[i][1], best);
            } else break;
        }
        if (best == -1) return -1;
        rec.push_back(best);
        for (; i < clips.size(); ++i) {
            auto p = lower_bound(rec.begin(), rec.end(), clips[i][0]);
            if (p == rec.end()) break;  // 不能再插入了, 由于rec是按clips[i][0]排序的, 可以提前终止
            // 从p开始都可以插入
            auto t = lower_bound(p + 1, rec.end(), clips[i][1]);
            // [p + 1, t)
            fill(p + 1, t, clips[i][1]); 
            if (t - (p + 1) <= 0) {
              rec.push_back(clips[i][1]);
            }
        }
        auto p = lower_bound(rec.begin(), rec.end(), T);
        if (p == rec.end()) return -1;
        return p - rec.begin();
    }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int> > clips;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    clips.push_back({a, b});
  }
  int T;
  cin >> T;
  cout << Solution().videoStitching(clips, T) << endl;
  return 0;
}
