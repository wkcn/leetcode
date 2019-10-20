#include "common.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

#if 0
class Solution {
public:
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if (!root) return {};
    vector<vector<int> > result;
    queue<pair<TreeNode*, int> > q;
    q.push({root, root->val});
    map<TreeNode*, TreeNode*> parents;
    parents[root] = nullptr;
    while (!q.empty()) {
      pair<TreeNode*, int> p = q.front(); q.pop();
      TreeNode* r = p.first;
      int su = p.second;
      if (!(r->left) && !(r->right) && su == expectNumber) {
        AddPath(result, r, parents);
      }
      if (r->left) {
        parents[r->left] = r;
        q.push({r->left, su + r->left->val}); 
      }
      if (r->right) {
        parents[r->right] = r;
        q.push({r->right, su + r->right->val}); 
      }
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
private:
  void AddPath(vector<vector<int> > & result, TreeNode* r, const map<TreeNode*, TreeNode*> &parents) {
    vector<int> vs;
    while (r) {
      vs.push_back(r->val);
      r = parents.at(r);
    }
    std::reverse(vs.begin(), vs.end());
    result.emplace_back(vs);
  }
};
#else

class Solution {
public:
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if (!root) return {};
    vector<vector<int> > result;
    vector<int> path;
    path.push_back(root->val);
    find(root, expectNumber - root->val, result, path); 
    sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b){return a.size() > b.size();});
    return result;
  }
private:
  void find(TreeNode* root, int expectNumber, vector<vector<int> >& result, vector<int>& path) {
    if (!(root->left) && !(root->right) && expectNumber == 0) {
      result.push_back(path);
      return;
    }
    if (root->left) {
      path.push_back(root->left->val);
      find(root->left, expectNumber - root->left->val, result, path);
      path.pop_back();
    }
    if (root->right) {
      path.push_back(root->right->val);
      find(root->right, expectNumber - root->right->val, result, path);
      path.pop_back();
    }
  }
};

#endif

int main() {
  int k;
  cin >> k;
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  vector<vector<int> > result = Solution().FindPath(root, k);
  for (int i = 0; i < result.size(); ++i) {
    PRINT_ARRAY(result[i]);
  }
  return 0;
}
