#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    string reverseWords(string s) {
        const int len = s.size();
        int i = 0, j;
        while (i < len) {
            while (i < len && s[i] == ' ') ++i;
            j = i + 1;
            while (j < len && s[j] != ' ') ++j;
            for (int x = i, y = j - 1; x < y; ++x, --y) {
                swap(s[x], s[y]);
            }
            i = j + 1;
        }
        // " ab cd "
        // " ba dc "
        // "cd ab"
        for (int x = 0, y = len - 1; x < y; ++x, --y) {
            swap(s[x], s[y]);
        }
        bool last_c = true;
        bool first = true;
        for (i = 0, j = 0; j < len; ++j) {
            if (s[j] != ' ') {
                if (!last_c && !first) s[i++] = ' ';
                s[i++] = s[j];
                last_c = true;
                first = false;
            }
            else {
                last_c = false;
            }
        }
        s.resize(i);
        return s;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    string reverseWords(string s) {
        const int len = s.size();
        reverse(s.begin(), s.end());
        int idx = 0, j;
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                j = i + 1;
                while (j < len && s[j] != ' ') ++j;
                // idx [i, j)
                int u;
                for (u = j-1; u >= i && idx < i; --u) {
                  s[idx++] = s[u];
                }
                if (idx >= i) {
                  for (int y = u; y > idx; --y) { 
                    swap(s[idx++], s[y]);
                  }
                  idx = u + 1;
                }
                i = j;
            }
        }
        s.resize(idx);
        return s;
    }
};
#endif

int main() {
  string s;
  getline(cin, s);
  cout << Solution().reverseWords(s) << endl;
  return 0;
}
