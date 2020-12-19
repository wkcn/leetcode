#include "common.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        char last_c = -1;
        int cnt = 0;
        int p = 0;
        for (char c : chars) {
            if (c == last_c) ++cnt;
            else {
                update(chars, p, cnt, last_c);
                last_c = c;
                cnt = 1;
            }
        }
        update(chars, p, cnt, last_c);
        return p;
    }
    void update(vector<char> &chars, int &p, int cnt, char c) {
        if (cnt == 0) return;
        if (cnt == 1) {
          chars[p++] = c;
          return;
        }
        chars[p++] = c;
        for (char e : to_string(cnt)) {
          chars[p++] = e;
        }
    }
};

int main() {
  vector<char> chars;
  INPUT_ARRAY(chars); 
  cout << Solution().compress(chars) << endl;
  PRINT_ARRAY(chars);
  return 0;
}
