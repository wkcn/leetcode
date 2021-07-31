#include "common.h" 

struct TreeNode {
		int val;
	 TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      queue<pair<TreeNode*, int>> q;
      q.push({root, 0}); // node, cols
      using T = tuple<int, int, int>;
      vector<T> buf; // val, cols, rows 
      int row = 0;
      while (!q.empty()) {
        int size = q.size();
        while (size--) {
          auto [r, c] = q.front(); q.pop();
          buf.emplace_back(r->val, c, row);
          if (r->left) q.push({r->left, c - 1});
          if (r->right) q.push({r->right, c + 1});
        }
        ++row;
      }
      sort(buf.begin(), buf.end(), [](T &a, T &b) {
        if (std::get<1>(a) != std::get<1>(b)) return std::get<1>(a) < std::get<1>(b);
        if (std::get<2>(a) != std::get<2>(b)) return std::get<2>(a) < std::get<2>(b);
        return std::get<0>(a) < std::get<0>(b);
      });
      vector<vector<int>> ans;
      for (int i = 0; i < buf.size(); ++i) {
        if (i == 0 || std::get<1>(buf[i-1]) != std::get<1>(buf[i])) {
          ans.push_back({std::get<0>(buf[i])});
        } else {
          ans.back().push_back(std::get<0>(buf[i]));
        }
      }
      return ans;
    }
};

int main() {
  return 0;
}
