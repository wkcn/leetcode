/*
小扣打算去秋日市集，由于游客较多，小扣的移动速度受到了人流影响：

小扣从 x 号站点移动至 x + 1 号站点需要花费的时间为 inc；
小扣从 x 号站点移动至 x - 1 号站点需要花费的时间为 dec。
现有 m 辆公交车，编号为 0 到 m-1。小扣也可以通过搭乘编号为 i 的公交车，从 x 号站点移动至 jump[i]*x 号站点，耗时仅为 cost[i]。小扣可以搭乘任意编号的公交车且搭乘公交次数不限。

假定小扣起始站点记作 0，秋日市集站点记作 target，请返回小扣抵达秋日市集最少需要花费多少时间。由于数字较大，最终答案需要对 1000000007 (1e9 + 7) 取模。

注意：小扣可在移动过程中到达编号大于 target 的站点。

示例 1：

输入：target = 31, inc = 5, dec = 3, jump = [6], cost = [10]

输出：33

解释：
小扣步行至 1 号站点，花费时间为 5；
小扣从 1 号站台搭乘 0 号公交至 6 * 1 = 6 站台，花费时间为 10；
小扣从 6 号站台步行至 5 号站台，花费时间为 3；
小扣从 5 号站台搭乘 0 号公交至 6 * 5 = 30 站台，花费时间为 10；
小扣从 30 号站台步行至 31 号站台，花费时间为 5；
最终小扣花费总时间为 33。

示例 2：

输入：target = 612, inc = 4, dec = 5, jump = [3,6,8,11,5,10,4], cost = [4,7,6,3,7,6,4]

输出：26

解释：
小扣步行至 1 号站点，花费时间为 4；
小扣从 1 号站台搭乘 0 号公交至 3 * 1 = 3 站台，花费时间为 4；
小扣从 3 号站台搭乘 3 号公交至 11 * 3 = 33 站台，花费时间为 3；
小扣从 33 号站台步行至 34 站台，花费时间为 4；
小扣从 34 号站台搭乘 0 号公交至 3 * 34 = 102 站台，花费时间为 4；
小扣从 102 号站台搭乘 1 号公交至 6 * 102 = 612 站台，花费时间为 7；
最终小扣花费总时间为 26。

提示：

1 <= target <= 10^9
1 <= jump.length, cost.length <= 10
2 <= jump[i] <= 10^6
1 <= inc, dec, cost[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/meChtZ
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "common.h"


// 特别要注意数据类型
// 注意什么时候加, 什么时候减
typedef unsigned long long ULL;
class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        unordered_map<int, ULL> buf;
        function<ULL(int)> F = [&](int target) -> ULL {
            if (target == 1) return inc;
            auto p = buf.find(target);
            if (p != buf.end()) return p->second;
            ULL best = (ULL)inc * target;
            for (int t = 0; t < jump.size(); ++t) {
                int j = jump[t], c = cost[t];
                int d = target / j, u = target % j;
                if (d > 0) {
                  best = min(best, F(d) + c + (ULL)u * inc);
                }
                if (u > 0) {
                    best = min(best, F(d + 1) + c + (ULL)(j - u) * dec);
                }
            }
            return buf[target] = best;
        };
        return F(target) % 1000000007;
    }
};


int main() {
  int target, inc, dec;
  vector<int> jump, cost;
  cin >> target >> inc >> dec;
  INPUT_ARRAY(jump);
  INPUT_ARRAY(cost);
  cout << Solution().busRapidTransit(target, inc, dec, jump, cost) << endl;
  return 0;
}
