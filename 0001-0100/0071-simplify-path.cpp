#include "common.h"

class Solution {
public:
    string simplifyPath(string path) {
      vector<string> vs;
      int i = 0;
      string buf;
      while (i < path.size()) {
        if (path[i] == '/') {
          if (!buf.empty())
            vs.push_back(buf);
          buf.clear();
          ++i;
          while (i < path.size() && path[i] == '/') ++i;
        } else {
          buf += path[i];
          ++i;
        }
      }
      if (!buf.empty()) vs.push_back(buf);
      deque<string> q;
      for (string s : vs) {
        if (s == "..") {
          if (!q.empty())
            q.pop_back();
        } else if (s == ".") {
        } else {
          q.emplace_back(s);
        }
      }
      if (q.empty()) return "/";
      string out;
      while (!q.empty()) {
        out += '/';
        out += q.front(); q.pop_front();
      }
      return out;
    }
};

int main() {
  while (1) {
    string s; cin >> s;
    cout << Solution().simplifyPath(s) << endl;
  }
  return 0;
}
