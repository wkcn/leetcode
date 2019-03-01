#include <iostream>
#include <chrono>
#include <list>
#include <vector>
#include <random>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unistd.h>
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

template <typename ListNode>
ListNode* INPUT_LIST() {
  int n;
  cin >> n;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while(n--) {
    int val;
    cin >> val;
    tail->next = new ListNode(val);
    tail = tail->next;
  }
  return dummy.next;
}

template <typename ListNode>
void PRINT_LIST(ListNode* head) {
  bool first = true;
  while(head) {
    if (!first) cout << " -> ";
    else first = false;
    cout << head->val;
    head = head->next;
  }
  cout << endl;
}


class Timer {
using time_point = std::chrono::steady_clock::time_point;
using ms_type = std::chrono::duration<int, ratio<1, 1000> >;
using milliseconds = std::chrono::milliseconds;
public:
  Timer(const string name="") : name_(name) {reset();}
  void tic() {
    tic_time_ = get_time_now();
  }
  void toc() {
    time_point now_time = get_time_now();
    cout << "Timer";
    if (name_.size()) cout << "[" << name_ << "]";
    cout << ": " << "toc: " << get_time_diff(now_time, tic_time_) << "ms tot: " << get_time_diff(now_time, reset_time_) << "ms" << endl;
  }
  void reset() {
    reset_time_ = get_time_now();
  }
private:
  time_point get_time_now() {
    return std::chrono::steady_clock::now();
  }
  int get_time_diff(time_point a, time_point b) {
    milliseconds diff = std::chrono::duration_cast<milliseconds>(a - b);
    return diff.count(); 
  }
private:
  string name_;
  time_point reset_time_;
  time_point tic_time_;
};
