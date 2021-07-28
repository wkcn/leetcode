#include "common.h"

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
      unordered_map<int, int> ma;
      for (int i = 0; i < target.size(); ++i) ma[target[i]] = i;
      vector<int> seq;
      for (int x : arr) {
        auto p = ma.find(x);
        if (p != ma.end()) seq.push_back(p->second); 
      }
      // 找最长递增数列
      vector<int> d;
      for (int x : seq) {
        auto p = lower_bound(d.begin(), d.end(), x);
        if (p == d.end()) d.push_back(x);
        else *p = x;
      }
      return target.size() - d.size();
    }
};

int main() {
  vector<int> target{5, 1, 3};
  vector<int> arr{9, 4, 2, 3, 4};
  cout << Solution().minOperations(target, arr) << endl;
}
