#include "common.h"

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct INode {
  int val;
  int left, right;
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      unordered_map<TreeNode*, int> n2i;
      auto get_id = [&](TreeNode *t) -> int {
        auto p = n2i.insert({t, n2i.size()});
        return p.first->second;
      };
      unordered_map<int, INode> ma;
      // 注意空节点
      if (root) {
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
          TreeNode *t = q.front(); q.pop();
          int id = get_id(t);
          int left = -1, right = -1;
          if (t->left) {
            left = get_id(t->left);
            q.push(t->left);
          }
          if (t->right) {
            right = get_id(t->right);
            q.push(t->right);
          }
          ma[id] = INode{t->val, left, right};
        }
      }
      string ans(4 + ma.size() * sizeof(INode), 0);
      char *p = (char*)ans.c_str();
      *(int*)p = ma.size();
      p += sizeof(int);
      for (int i = 0; i < ma.size(); ++i) {
        INode *r = ((INode*)p) + i;
        memcpy(r, &ma[i], sizeof(INode));
      }
      return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      const char *p = data.c_str();
      int n = *(int*)p;
      // 注意空节点
      if (n == 0) return nullptr;
      vector<TreeNode*> nodes(n);
      for (int i = 0; i < n; ++i) nodes[i] = new TreeNode(-1);
      const INode *e = (const INode*)(p + sizeof(int));
      for (int i = 0; i < n; ++i) {
        nodes[i]->val = e[i].val;
        if (e[i].left != -1)
          nodes[i]->left = nodes[e[i].left];
        if (e[i].right != -1)
          nodes[i]->right = nodes[e[i].right];
      }
      return nodes[0];
    }
};

int main() {
  return 0;
}
