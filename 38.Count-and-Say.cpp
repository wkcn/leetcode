#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
      queue<int> qu;
      qu.push(1);
      while (--n) {
        int len = qu.size();
        int val = qu.front(); qu.pop();
        int count = 1;
        for (int i = 1; i < len; ++i) {
          int cv = qu.front(); qu.pop();
          if (cv == val) ++count;
          else {
            qu.push(count);
            qu.push(val);
            val = cv;
            count = 1;
          };
        }
        qu.push(count);
        qu.push(val);
      }
      string res;
      while (!qu.empty()) {
        res += '0' + qu.front(); qu.pop();
      }
      return res;
    }
};

class Solution2 {
public:
    string countAndSay(int n) {
      if (n == 1) return "1";
      vector<pair<int, int> > vs; // [(val, count), ...]
      vector<pair<int, int> > old;
      vs.push_back({1, 1});
      while (--n) {
        old = std::move(vs);
        vs.clear();
        for (auto &p : old) {
          stack<int> st;
          int v = p.second;
          if (v >= 4) cout << "WK" << endl;
          while (v > 0) {
            st.push(v % 10);
            v /= 10;
          }
          while (!st.empty()) {
            say(st.top(), vs);
            st.pop();
          }

          say(p.first, vs);
        }
      }
      string res;
      for (auto &p : vs) {
        char c = p.first + '0';
        for (int i = 0; i < p.second; ++i) {
          res += c;
        }
      }
      return res;
    }
private:
    void say(int v, vector<pair<int, int> > &vs) {
      if (vs.empty()) {
        vs.push_back({v, 1});
        return;
      }
      pair<int, int> &back = vs.back();
      if (back.first == v) {
        ++back.second;
      } else {
        vs.push_back({v, 1});
      }
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().countAndSay(n) << endl;
  return 0;
}
