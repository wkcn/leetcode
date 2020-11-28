#include "common.h"

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> b1(60); b1[0] = 0;
        for (int i = 1; i < 60; ++i) {
            b1[i] = b1[i >> 1] + (i & 1);
        }
        vector<vector<int> > cs(7);
        for (int i = 0; i < 60; ++i) {
            cs[b1[i]].push_back(i);
        }
        vector<string> ans;
        // 要排除不可能的数字
        for (int u = 0; u <= min(4, num); ++u) {
            int d = num - u;
            if (d > 6) continue;
            for (int up_v : cs[u]) {
                if (up_v < 12) {
                    for (int down_v : cs[d]) {
                        if (down_v < 60) {
                            ans.push_back(to_string(up_v) + ':' + (down_v < 10 ? '0' + to_string(down_v) : to_string(down_v)));
                        } else break;
                    }
                } else break;
            }
        }
        return ans;
    }
};

int main() {
  int num; cin >> num;
  PRINT_ARRAY(Solution().readBinaryWatch(num));
  return 0;
}
