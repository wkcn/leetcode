#include "common.h"

#define SOLUTION 1

#if SOLUTION == 1 

// 比较简单的写法，注意排列是正序还是逆序
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int, int> > vs;
        const int N = height.size();
        for (int i = 0; i < N; ++i) {
            vs.push_back({height[i], weight[i]});
        }
        sort(vs.begin(), vs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        vector<int> min_weight;
        for (int i = 0; i < N; ++i) {
            // 注意相同身高的处理
            int h = vs[i].first;
            int w = vs[i].second;
            auto p = lower_bound(min_weight.begin(), min_weight.end(), w);
            if (p == min_weight.end()) {
                min_weight.push_back(w);
            } else {
                if (*p > w) {
                    *p = w;
                }
            }
        }
        return min_weight.size();
    }
};

#elif SOLUTION == 2

// TODO: 假如两个变量都是正序排序，应该怎么处理？

#endif

int main() {
  vector<int> height, weight;
  INPUT_ARRAY(height);
  INPUT_ARRAY(weight);
  cout << Solution().bestSeqAtIndex(height, weight) << endl;
  return 0;
}
