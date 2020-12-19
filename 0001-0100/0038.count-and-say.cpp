#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string t;
            char last_c = -1;
            int cnt = 0;
            for (char c : s) {
                if (last_c == c) {
                    ++cnt;
                } else {
                    if (last_c != -1) {
                        t += to_string(cnt);
                        t += last_c;
                    }
                    cnt = 1;
                    last_c = c;
                }
            }
            if (cnt > 0) {
                t += to_string(cnt);
                t += last_c;
            }
            s = move(t);
        }
        return s;
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().countAndSay(n) << endl;
  return 0;
}
