#include "common.h"

/*
 * 
 * 为了平分两个正方形，直线一定经过这两个正方形的中心(cx1, cy1)和(cx2, cy2)，可以用两点式

(x - cx1) / (cx2 - cx1) = (y - cy1) / (cy2 - cy1) 
推导出直线公式。

需要处理两种特殊情况，cx1 == cx2和cy1 == cy2:
当cx1 == cx2时，直线与y轴平行；
当cy1 == cy2时，直线与x轴平行。

一条直线平分正方形时，会穿过这个正方形的两条边，交点的x坐标或y坐标会与正方形的一个顶点的x坐标或y坐标相等。因此，将正方形的顶点代入直线方程，得到每个正方形有四个候选点，只选择在正方形内的候选点。

最后对顶点集res进行排序，所求顶点为排序后的res数组的第一个顶点和最后一个顶点。

 */

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        // 计算两个正方形中心(cx1, cy1), (cx2, cy2)
        double cx1 = square1[0] + ((double)square1[2]) / 2;
        double cy1 = square1[1] + ((double)square1[2]) / 2;

        double cx2 = square2[0] + ((double)square2[2]) / 2;
        double cy2 = square2[1] + ((double)square2[2]) / 2;

        vector<pair<double, double> > res; // 候选顶点集
        // 处理特殊情况cx1 == cx2和cy1 == cy2
        if (cx1 == cx2) {
            res.push_back({cx1, square1[1]});
            res.push_back({cx1, square2[1]});
            res.push_back({cx1, square1[1]+square1[2]});
            res.push_back({cx1, square2[1]+square2[2]});
        } else if (cy1 == cy2) {
            res.push_back({square1[0], cy1});
            res.push_back({square2[0], cy1});
            res.push_back({square1[0]+square1[2], cy1});
            res.push_back({square2[0]+square2[2], cy1});
        } else {
            // 直线方程f(y)
            auto fy = [=](double y) -> double {
                const double k = (cx2 - cx1) / (cy2 - cy1);
                return k * (y - cy1) + cx1;
            };
            // 直线方程f(x)
            auto fx = [=](double x) -> double {
                const double k = (cy2 - cy1) / (cx2 - cx1);
                return k * (x - cx1) + cy1;
            };
            for (auto &sq : {square1, square2}) {
                for (auto &p : vector<pair<double, double> >{
                    {fy(sq[1]), sq[1]},
                    {fy(sq[1]+sq[2]), sq[1]+sq[2]},
                    {sq[0], fx(sq[0])},
                    {sq[0]+sq[2], fx(sq[0]+sq[2])}})
                {
                    // 判断候选顶点是否在正方形中
                    if (p.first >= sq[0] && p.first <= sq[0] + sq[2]) {
                        if (p.second >= sq[1] && p.second <= sq[1] + sq[2]) {
                            res.push_back(p);
                        }
                    }
                }
            }
        }
        // 对顶点集排序
        sort(res.begin(), res.end());
        // 所求顶点为排序后的`res`数组的第一个顶点和最后一个顶点。
        return {
            res.front().first,
            res.front().second,
            res.back().first,
            res.back().second,
        };
    }
};

int main() {
  vector<int> square1;
  vector<int> square2;
  INPUT_ARRAY(square1);
  INPUT_ARRAY(square2);
  PRINT_ARRAY(Solution().cutSquares(square1, square2));
  return 0;
}
