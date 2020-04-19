// 太难了，TODO: 看一下别人的题解
#include "common.h"

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    /*
     * s1: acbacbacbacb 
     * s2: ab
     */
    if (n1 == 0) return 0;
    const int l1 = s1.size();
    const int l2 = s2.size();
    // create jump table 
    array<int, 256> table;
    table.fill(-1); 
    for (int i = l1-1; i >= 0; --i) {
      const char &c = s1[i];
      table[c] = i + 1;
    }
    vector<array<int, 256> > tables(l1 + 1);
    for (int i = l1-1; i >= 0; --i) {
      tables[i+1] = table;
      const char &c = s1[i];
      table[c] = i + 1;
    }
    tables[0] = table;

    unordered_map<int, pair<int, int>> ma;
    int i = 0, j = 0;
    int rep1 = 0;
    int rep2 = 0;
    while (1) {
      const char &c = s2[j];
      int jump_pos = tables[i][c];
      if (jump_pos == -1) return 0;
      if (jump_pos <= i) {
        ++rep1;
        auto it = ma.find(j);
        //cout << "RECORD: " << j << ", " << rep1 << ", " << rep2 << endl;
        if (it == ma.end()) {
          ma[j] = {rep1, rep2};
        } else {
          auto [last_rep1, last_rep2] = ma[j];
          int diff_rep1 = rep1 - last_rep1;
          int diff_rep2 = rep2 - last_rep2;
          // 还没有进入循环节 -> 进入循环节 -> 剩余部分
          int head = (last_rep2); 
          int block1 = (n1 - last_rep1) / diff_rep1;
          int mid = block1 * diff_rep2; 
          //cout << "N!N!N!: " << n1 << ", " << last_rep1 << ", " << diff_rep1 << ", " << diff_rep2 << endl;
          int tail = 0;
          i = 0;
          int g = n1 - last_rep1 - block1 * diff_rep1;
          //cout << "G: " << g << ", J: " << j << endl;
          while (g > 0) {
            const char &c = s2[j];
            int jump_pos = tables[i][c];
            if (jump_pos <= i) {
              if (--g <= 0) break;
            }
            i = jump_pos;
            if (++j >= l2) {
              j = 0;
              ++tail;
            }
          }
          //cout << head << ", " << mid << ", " << tail << endl;
          return (head + mid + tail) / n2;
        }
      }
      if (j >= l2 - 1) {
        ++rep2;
      }
      if (++j >= l2) {
        j = 0;
      }
      i = jump_pos;
    }
    return 0;
  }
};

int main() {
  string s1, s2;
  int n1, n2;
  cin >> s1 >> n1 >> s2 >> n2;
  cout << Solution().getMaxRepetitions(s1, n1, s2, n2) << endl;
  return 0;
}
