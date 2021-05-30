#include "common.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnts;
        for (string &s : words) ++cnts[s];
        vector<pair<string, int>> vs(cnts.begin(), cnts.end());
        auto cmp = [&](int a, int b) -> bool {
          auto pa = vs[a], pb = vs[b];
          if (pa.second != pb.second) return pa.second > pb.second;
          return pa.first < pb.first;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq{cmp};
        for (int i = 0; i < vs.size(); ++i) {
          pq.push(i);
          if (pq.size() > k) pq.pop();
        }
        k = min(k, (int)pq.size());
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
          ans[i] = vs[pq.top()].first;
          pq.pop();
        }
        return ans;
    }
};

int main() {
  vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
  int k = 2;
  PRINT_ARRAY(Solution().topKFrequent(words, k));
  return 0;
}
