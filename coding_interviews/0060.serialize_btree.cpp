/*
 * 题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
 */
/*
 * 特别要注意，vector变化时不要取地址、取引用
 * 比如:
 * vector<int> v;
 * const int &a = v[0];
 * v[0] = some_function_to_change_the_capacity_of_v();
 * 都是错的
 * https://github.com/wkcn/gcc_bug
 */
#include "common.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct STreeNode {
  int val;
  int left, right;
  STreeNode() {
  }
  STreeNode(int x) : val(x), left(-1), right(-1) {
  }
};

class Solution {
public:
  char* Serialize(TreeNode *root) {    
    if (!root) return nullptr;
    vector<STreeNode> vs;
    stack<TreeNode*> st;
    map<TreeNode*, int> ma;
    st.push(root);
    while (!st.empty()) {
      TreeNode* r = st.top(); st.pop();
      int si = get_snode(vs, ma, r);
      if (r->left) {
        int p = get_snode(vs, ma, r->left);
        vs[si].left = p;
        st.push(r->left);
      }
      if (r->right) {
        vs[si].right = get_snode(vs, ma, r->right);
        st.push(r->right);
      }
    }
    char *buf = new char[4 + vs.size() * sizeof(STreeNode)];
    *reinterpret_cast<int*>(buf) = vs.size();
    memcpy(buf + 4, vs.data(), vs.size() * sizeof(STreeNode));
    return buf;
  }
  TreeNode* Deserialize(char *str) {
    if (!str) return nullptr;
    int len = *reinterpret_cast<int*>(str);
    STreeNode *sr = reinterpret_cast<STreeNode*>(str + 4);
    vector<TreeNode*> vs;
    for (int i = 0; i < len; ++i) {
      vs.push_back(new TreeNode{sr[i].val});
    }
    for (int i = 0; i < len; ++i) {
      if (sr[i].left != -1)
        vs[i]->left = vs[sr[i].left];
      if (sr[i].right != -1)
        vs[i]->right = vs[sr[i].right];
    }
    return vs[0];
  }
private:
  int get_snode(vector<STreeNode> &vs, map<TreeNode*, int> &ma, TreeNode* r) {
    if (!ma.count(r)) {
      ma[r] = vs.size();
      vs.push_back(r->val);
    }
    return ma[r];
  } 
};

int main() {
  Solution so;
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  char* str = so.Serialize(root);
  PRINT_BTREE_VLR(so.Deserialize(str));
  return 0;
}
