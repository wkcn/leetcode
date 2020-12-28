// TODO: 尝试一下题解里的DP, 返回值为一个变量，和自己的公式有什么不同
#include "common.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int two = 0, one = 0;
        for (int x : cost) {
            /*
                new_one = min(one, two) + x;
                new_two = one;
             */
             int old = one;
             one = min(one, two) + x;
             two = old;
        }
        return min(one, two);
    }
};

int main() {
  vector<int> cost;
  INPUT_ARRAY(cost);
  cout << Solution().minCostClimbingStairs(cost) << endl;
  return 0;
}
