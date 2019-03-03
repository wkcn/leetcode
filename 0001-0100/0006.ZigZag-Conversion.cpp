// https://blog.csdn.net/MapleJam/article/details/52923281
#include "common.h"

class Solution {
public:
    string convert(string s, int numRows) {
        int k = (numRows-1) * 2;
        if (k == 0)k = 1;
        string buf;
        for (int i = 0;i < numRows;++i){
            int step = k - i * 2;
            if (step == 0)step = k;
            int p = i;
            while(p < s.size()){
                buf += s[p];
                p += step;
                if (step != k)step = k - step;
            }
        }
        return buf;
    }
};

int main() {
  Solution so;
  string s = "PAYPALISHIRING";
  cout << so.convert(s, 3) << endl;
  return 0;
}
