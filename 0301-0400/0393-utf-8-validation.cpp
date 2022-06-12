#include "common.h"

class Solution {
  public:
    bool validUtf8(vector<int>& data) {
      int i = 0;
      const int size = data.size();
      while (i < size) {
        if (!(data[i] & 0x80)) ++i;
        else {
          // 多字节
          int u = 0x80;
          int cnt = 0;
          while (data[i] & u) {
            ++cnt;
            u >>= 1;
          }
          // cnt表示前面有几个1
          if (cnt == 1 || cnt > 4 || size - i < cnt) return false;
          for (int c = 1, j = i + 1; c < cnt; ++c, ++j) {
            if ((data[j] >> 6) != 0b10) return false;
          }
          i += cnt;
        }
      }
      return true;
    }
};

int main() {
  // vector<int> data{197, 130, 1};
  // vector<int> data{145};
  vector<int> data{250, 145, 145, 145, 145};
  cout << Solution().validUtf8(data) << endl;;
  return 0;
}
