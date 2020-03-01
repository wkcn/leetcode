#include "common.h"

// TODO: 用双指针方法更简单，因为只有一次编辑
class Solution {
public:
    bool oneEditAway(string first, string second) {
      // 插入，删除，替换
      // 编辑距离问题
      // dis[i][j] 代表first[:i]和second[:j]的编辑距离
      // dis[i+1][j+1] = min{
      //                    dis[i][j] if first[i] == second[j]
      //        otherwise,  dis[i][j+1] + 1, dis[i+1][j] + 1
      //                    dis[i][j] + 1 # 替换
      // }
      const int M = first.size(), N = second.size(); 
      if (M > N) return oneEditAway(second, first);
      // M <= N
      vector<int> dis(M + 1);
      for (int k = 0; k <= M; ++k) dis[k] = k;

      for (int i = 0; i < N; ++i) {
        int last = dis[0]; // 注意，这个应该在dis[0] = i + 1; 前面!!!!!!
        dis[0] = i + 1;
        for (int j = 0; j < M; ++j) {
          int old = dis[j+1];
          // 注意应该用哪个下标！！！
          if (first[j] == second[i]) {
            dis[j+1] = last; // 这里是左上角
          } else {
            //dis[j+1] = min(min(dis[j+1], dis[j]), last) + 1;
            int v = min(last, min(dis[j], dis[j+1])) + 1;
            dis[j+1] = v;
          }
          last = old;
          // 在中途判断dis的值只能起到剪枝的作用
        }
      }
      return dis[M] <= 1;
    }
};

int main() {
  string first, second;
  cin >> first >> second;
  cout << Solution().oneEditAway(first, second) << endl;
  return 0;
}
