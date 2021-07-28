#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
      if (height.size() < 3) return 0;
      int i = 0, j = height.size() - 1;
      int left = height[0], right = height.back();
      int ans = 0;
      while (i < j) {
        if (height[i] <= height[j]) {
          ans += max(min(left, right) - height[i++], 0);
          left = max(left, height[i]);
        } else {
          ans += max(min(left, right) - height[j--], 0);
          right = max(right, height[j]);
        }
      }
      return ans;
    }
};

int main() {
  vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
  cout << Solution().trap(height) << endl;
  return 0;
}
