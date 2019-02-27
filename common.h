#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

template <typename T>
void INPUT_ARRAY(vector<T> &vs) {
  int n;
  cin >> n;
  T data;
  while(n--) {
    cin >> data;
    vs.push_back(data);
  }
}

template <typename T>
void PRINT_ARRAY(const vector<T> &vs) {
  bool first = true;
  for (const T &data : vs) {
    if (!first) cout << ", ";
    else first = false;
    cout << data;
  }
  cout << endl;
}

template <typename TreeNode>
TreeNode* INPUT_BTREE_VLR() {
  stack<TreeNode**> st;
  TreeNode* root = nullptr;
  st.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode** p = st.top(); st.pop();
    if (v) {
      // valid
      *p = new TreeNode(v);
      st.push(&((*p)->right));
      st.push(&((*p)->left));
    }
  }
  return root;
}

template <typename TreeNode>
TreeNode* INPUT_BTREE_LEVEL() {
  queue<TreeNode**> q;
  TreeNode* root = nullptr;
  q.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode** p = q.front(); q.pop();
    if (v) {
      // valid
      *p = new TreeNode(v);
      q.push(&((*p)->left));
      q.push(&((*p)->right));
    }
  }
  return root;
}
