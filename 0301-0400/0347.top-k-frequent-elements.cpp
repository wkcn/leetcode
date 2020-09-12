// TODO: 快排等求topk的方法
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int x : nums) ++cnts[x];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q; // 取出最小次数
        vector<int> out;
        for (auto p : cnts) {
            if (q.size() < k) {
                int id = out.size();
                out.push_back(p.first);
                q.push({p.second, id});
            } else {
                if (p.second > q.top().first) {
                    int id = q.top().second;
                    out[id] = p.first;
                    q.pop();
                    q.push({p.second, id});
                }
            }
        }
        return out;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int x : nums) ++cnts[x];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q; // 取出最小次数
        for (auto p : cnts) {
          if (q.size() < k) {
            q.push({p.second, p.first});
          } else {
            if (p.second > q.top().first) {
              q.pop();
              q.push({p.second, p.first});
            }
          }
        }
        vector<int> out;
        while (!q.empty()) {
          out.push_back(q.top().second);
          q.pop();
        }
        return out;
    }
};


#endif

int main() {
  vector<int> nums; int k;
  INPUT_ARRAY(nums); cin >> k;
  PRINT_ARRAY(Solution().topKFrequent(nums, k));
  return 0;
}
