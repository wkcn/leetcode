// 好题, 填桶
#include "common.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> cnts{0};
        for (char c : tasks) {
            ++cnts[c - 'A'];
        }
        int max_cnt = *max_element(cnts.begin(), cnts.end());
        int cnt = 0;
        for (int x : cnts) if (x == max_cnt) ++cnt;
        // 一种是没有满的状态， 另一种是满了的状态
        // 如果没有满， ans = (max_cnt - 1) * (1 + n) + cnt
        // 如果满了，ans = tasks.size()
        return max((max_cnt - 1) * (1 + n) + cnt, (int)tasks.size());
    }
};

int main() {
  vector<char> tasks; int n;
  INPUT_ARRAY(tasks); cin >> n;
  cout << Solution().leastInterval(tasks, n) << endl;
  return 0;
}
