// 线段树 - 闭区间版本
// DFS找编号映射 + 线段树
// Reference: https://leetcode-cn.com/problems/coin-bonus/solution/di-yi-ci-xie-xian-duan-shu-dai-ma-cong-meng-bi-dao/
// 不能用节点存储和，因为那样update时需要向上、向下更新
// 注意用long long避免数据越界
// TODO: 学习其他方法
#include "common.h"

// pos是所有节点编号，根节点为0
// id为叶节点编号
//

typedef long long LL;

const LL MOD = 1000000007;
class SegmentTree {
public:
  SegmentTree(int n) : tree(4 * n, 0), lazy(4 * n, 0) {
  }
  void Update(int pos, int left, int right, int opLeft, int opRight, int value) {
    // left, right, opLeft, opRight都是id
    // opLeft, opRight 都是操作范围
    PushDown(pos, left, right);
    if (right < opLeft || left > opRight) return;
    if (opLeft <= left && right <= opRight) {
      // 刚好一个元素
      lazy[pos] = value;
      PushDown(pos, left, right);
    } else {
      int mid = left + ((right - left) >> 1);
      // 左子节点
      Update(pos * 2 + 1, left, mid, opLeft, opRight, value);
      // 右子节点
      Update(pos * 2 + 2, mid + 1, right, opLeft, opRight, value);
      // 更新完子节点后，更新当前节点的tree
      tree[pos] = ((LL)tree[2 * pos + 1] + (LL)tree[2 * pos + 2]) % MOD;
    }
  }

  int Query(int pos, int left, int right, int opLeft, int opRight) {
    if (right < opLeft || left > opRight) return 0;
    PushDown(pos, left, right);
    if (opLeft <= left && right <= opRight) {
      // 如果当前节点[left, right]已经是要查询的范围的子集，返回该节点的value
      return tree[pos];
    }
    int mid = left + ((right - left) >> 1);
    return ((LL)Query(pos * 2 + 1, left, mid, opLeft, opRight) + \
           (LL)Query(pos * 2 + 2, mid + 1, right, opLeft, opRight)) % MOD; 
  }
private:
  void PushDown(int pos, int left, int right) {
    if (lazy[pos] == 0) return;
    tree[pos] += lazy[pos] * (right - left + 1);
    if (left < right) {
      lazy[pos * 2 + 1] += lazy[pos];
      lazy[pos * 2 + 2] += lazy[pos];
    }
    lazy[pos] = 0;
  }
private:
  vector<int> tree;
  vector<int> lazy;

public:

#ifdef DEBUG
  void Debug() {
    cout << "=====" << endl;
    cout << "tree: ";
    PRINT_ARRAY(tree);
    cout << "lazy: ";
    PRINT_ARRAY(lazy);
    cout << "=====" << endl;
  }
#endif

};

class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
      SegmentTree tree(n);
      // 需要建立树ID与员工ID的映射关系, VLR
      vector<pair<int, int> > ma = GetMap(n, leadership); // first是该节点的ID, second是该节点的最右子节点的ID
      vector<int> ans;
      for (auto &op : operations) {
        switch (op[0]) {
          case 1:
            tree.Update(0, 0, n - 1, ma[op[1]].first, ma[op[1]].first, op[2]); 
            break;
          case 2:
            tree.Update(0, 0, n - 1, ma[op[1]].first, ma[op[1]].second, op[2]); 
            break;
          case 3:
            ans.push_back(tree.Query(0, 0, n - 1, ma[op[1]].first, ma[op[1]].second));
            break;
        }
      }
      return ans;
    }
private:
    vector<pair<int, int> > GetMap(int n, vector<vector<int> > &leadership) {
      vector<pair<int, int> > ma(n + 1);
      vector<vector<int> > G(n + 1);
      for (auto &v : leadership) {
        G[v[0]].push_back(v[1]);
      }
      // 线段树ID
      int id = -1;
      function<void(int)> DFS = [&](int r) {
        // 先++id, 才能保证DFS调用结束时，id是右节点的ID
        ++id;
        ma[r].first = id;
        for (int child : G[r]) {
          DFS(child);
        }
        ma[r].second = id;  // 记录最后右节点的数值
        // cout << r << " : " << ma[r].first << ", " << ma[r].second << endl;
      };
      DFS(1);
      return ma;
    }
};

int main() {
  int n = 6;
  vector<vector<int> > leadership = {{1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4}};
  vector<vector<int> > operations = {{1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1}};
  PRINT_ARRAY(Solution().bonus(n, leadership, operations));
  return 0;
}
