#include "common.h"

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    int ans = 0;
    int left = 0, right = int(people.size()) - 1;
    sort(people.begin(), people.end());
    while (left <= right) {
      if (people[left] + people[right] <= limit) {
        ++left; --right;
      } else {
        --right;
      }
      ++ans;
    }
    return ans;
  }
};

int main() {
  vector<int> people{1, 2};
  int limit = 3;
  cout << Solution().numRescueBoats(people, limit) << endl;
  return 0;
}
