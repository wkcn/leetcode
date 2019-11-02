/*
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * 分类研究, 三种情况
 */
#include "common.h"

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

#define SOLUTION 1

#if SOLUTION == 0

class Solution {
public:
  TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    TreeLinkNode* last = nullptr;
    while (pNode) {
      if (pNode->right && pNode->right != last) {
        pNode = pNode->right;
        while (pNode->left) {
          pNode = pNode->left;
        }
        return pNode;
      }
      if (pNode->next && pNode->next->left == pNode) return pNode->next;
      // right
      last = pNode;
      pNode = pNode->next;
    }
    return nullptr;
  }
};

#elif SOLUTION == 1

class Solution {
public:
  TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (!pNode) return nullptr;
    if (pNode->right) {
      pNode = pNode->right;
      while (pNode->left) pNode = pNode->left;
      return pNode;
    }
    while (pNode->next) {
      if (pNode->next->left == pNode) return pNode->next;
      pNode = pNode->next;
    }
    return nullptr;
  }
};

#endif

int main() {
  vector<TreeLinkNode*> nodes;
  for (int i = 0; i < 3; ++i) {
    nodes.push_back(new TreeLinkNode(i));
  }
  //  0
  // 1 2
  nodes[0]->left = nodes[1];
  nodes[0]->right = nodes[2];
  nodes[1]->next = nodes[0];
  nodes[2]->next = nodes[0];
  for (int i = 0; i < 3; ++i) {
    cout << i << ": " << nodes[i] << endl;
  }
  cout << endl;
  Solution so;
  for (int i = 0; i < 3; ++i) {
    cout << i << ": " << so.GetNext(nodes[i]) << endl;
  }
  return 0;
}
