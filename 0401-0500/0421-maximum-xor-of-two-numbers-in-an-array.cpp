#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
      unsigned int ans = 0;
      for (int i = 31; i >= 0; --i) {
        ans <<= 1;
        int mask = ans | 1;
        unordered_set<int> se;
        for (int x : nums) {
          x >>= i;
          if (se.find(x ^ mask) != se.end()) {
            ans = mask;
            break;
          } else se.insert(x); 
        }
      }
      return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
      // TODO: Trie
    }
};

#endif

int main() {
  vector<int> nums{3, 10, 5, 25, 2, 8};
  cout << Solution().findMaximumXOR(nums) << endl;
  return 0;
}
