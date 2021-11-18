#include "common.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const int K = 3;
        if (nums.size() < K) return *max_element(nums.begin(), nums.end());
        list<int> li;
        for (int i = 0; i < nums.size(); ++i) {
          int x = nums[i];
          auto it = li.begin();
          while (it != li.end()) {
            if (x >= *it) {
              break;
            }
            ++it;
          }
          if (it == li.end()) {
            if (li.size() < K) li.push_back(x);
          } else if (x > *it) {
            li.insert(it, x);
            if (li.size() > K)
              li.pop_back();
          }
        }
        return li.size() >= K ? li.back() : li.front();
    }
};

int main() {
  {
  vector<int> nums{2, 2, 3, 1};
  cout << Solution().thirdMax(nums) << endl;
  }

  {
  vector<int> nums{1, 1, 2};
  cout << Solution().thirdMax(nums) << endl;
  }
  return 0;
}
