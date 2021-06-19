#include "common.h"

struct TNode {
  int value;
  TNode* nodes[2];
  TNode() {
    nodes[0] = nodes[1] = nullptr;
  }
  ~TNode() {
    delete nodes[0];
    delete nodes[1];
  }
};

/*
 * 可以一开始给根节点一个INT32_MAX
 * 如果根节点 <= m, 则一定存在结果
 */

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      TNode *tree = build_tree(nums);
      vector<int> ans(queries.size());
      for (int i = 0; i < queries.size(); ++i) {
        ans[i] = get_ans(tree, queries[i][0], queries[i][1]);
      }
      return ans;
    }
    int get_ans(TNode *r, int x, int m) {
      int ans = 0;
      for (int i = 31; i >= 0; --i) {
        ans <<= 1;
        int t = 1 - ((x >> i) & 1);
        if (r->nodes[t] && r->nodes[t]->value <= m) {
          ans |= 1;
          r = r->nodes[t];
        } else if (r->nodes[1-t] && r->nodes[1-t]->value <= m) {
          r = r->nodes[1-t];
        } else {
          return -1;
        }
      }
      return ans;
    }
    TNode* build_tree(vector<int> &nums) {
      TNode *root = new TNode();
      root->value = INT32_MIN;
      for (int x : nums) {
        TNode *p = root;
        for (int i = 31; i >= 0; --i) {
          TNode* &r = p->nodes[(x >> i) & 1];
          if (!r) {
            r = new TNode();
            r->value = x;
          } else r->value = min(r->value, x);
          p = r;
        }
      }
      return root;
    }
};

int main() {
  vector<int> nums{0, 1, 2, 3, 4};
  vector<vector<int>> queries{{3, 1}, {1, 3}, {5, 6}};
  PRINT_ARRAY(Solution().maximizeXor(nums, queries));
  return 0;
}
