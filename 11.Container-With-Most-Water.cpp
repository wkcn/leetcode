#include "common.h"

/*
 * 可以证明这种方法不会跳过最优解
 * 每次减少宽度有两个子集选择
 * 可以保证解在较长个边缘高度的一个子集里（因为宽度一样,边缘高度不一样）
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
      int i = 0, j = height.size() - 1;
      int best = 0;
      while (i < j) {
        int a = (j - i) * min(height[i], height[j]);
        if (a > best) best = a;
        if (height[i] < height[j]) ++i;
        else --j;
      }
      return best;
    }
};

/*
 * Heap
 * O(n^2)
 */
class Solution2 {
public:
    int maxArea(vector<int>& height) {
      int best = 0;
      vector<pair<int, int> > q;
      q.push_back({height[0], 0});
      for (int i = 1; i < height.size(); ++i) {
        int value = height[i];
        for (auto &p : q) {
          int cap = min(p.first, value) * (i - p.second);
          if (cap > best) best = cap;
        }
        if (value > q[0].first) {
          q.push_back({value, i});
          push_heap(q.begin(), q.end());
        }
      }
      return best;
    }
};

int main() {
  Solution so;
  vector<int> height;
  int n;
  cin >> n;
  while (n--) {
    int h;
    cin >> h;
    height.push_back(h);
  }
  cout << so.maxArea(height) << endl;
  return 0;
}
