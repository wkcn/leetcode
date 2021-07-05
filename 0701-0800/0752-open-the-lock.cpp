#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      unordered_set<string> se(deadends.begin(), deadends.end());
      if (se.count("0000")) return -1;
      // 要知道什么时候退出
      if (target == "0000") return 0;
      se.insert("0000");
      queue<string> q; q.push("0000");
      int step = 0;
      while (!q.empty()) {
        ++step;
        int n = q.size();
        while (n-- > 0) {
          string s = move(q.front()); q.pop();
          for (int i = 0; i < 4; ++i) {
            string y = s;
            for (int t = -1; t <= 1; t += 2) {
              y[i] = (s[i] - '0' + t + 10) % 10 + '0';
              if (y == target) return step;
              if (!se.count(y)) {
                se.insert(y);
                q.push(y);
              }
            }
          }
        }
      }
      return -1;
    }
};
#elif SOLUTION == 2
class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) return -1;
    // 要知道什么时候退出
    if (target == "0000") return 0;
    queue<string> q_source, q_target;
    unordered_set<string> se_source, se_target;
    q_source.push("0000"); q_target.push(target);
    se_source.insert("0000"); se_target.insert(target);
    int step = 0;
    auto bfs = [&](queue<string> &q, unordered_set<string> &se, unordered_set<string> &te) -> bool {
      int n = q.size();
      while (n-- > 0) {
        string s = move(q.front()); q.pop();
        for (string t : opt(s)) {
          if (dead.count(t) || se.count(t)) continue;
          if (te.count(t)) {
            return true;
          }
          se.insert(t);
          q.push(t);
        }
      }
      return false;
    };
    while (!q_source.empty() && !q_target.empty()) {
      ++step;
      bool b = false;
      if (q_source.size() < q_target.size()) {
        b = (bfs(q_source, se_source, se_target));
      } else {
        b = (bfs(q_target, se_target, se_source));
      } 
      if (b) {
        return step;
      }
    }
    return -1;
  }
  vector<string> opt(string &s) {
    vector<string> out;
    for (int i = 0; i < 4; ++i) {
      string t = s;
      // next
      t[i] = s[i] == '9' ? '0' : s[i] + 1; 
      out.push_back(t);
      // pre
      t[i] = s[i] == '0' ? '9' : s[i] - 1; 
      out.push_back(t);
    }
    return out;
  }
};
#endif

int main() {
  vector<string> deadends = {"0201","0101","0102","1212","2002"};
  string target = "0202";
  cout << Solution().openLock(deadends, target) << endl;
  return 0;
}
