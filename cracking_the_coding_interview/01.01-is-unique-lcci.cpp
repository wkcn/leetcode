#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool isUnique(string astr) {
      // 变量b存储的数组是一种数据结构！！
      bool b[256];
      memset(b, 0, sizeof(b));
      for (char c : astr) {
        if (b[c]) return false;
        b[c] = true;
      }
      return true;
    }
};
#elif SOLUTION == 2

class Solution {
public:
  // Bitmap
  bool isUnique(string astr) {
    int mask = 0;
    for (char c : astr) {
      int u = c - 'a';
      if (mask & (1 << u)) return false; 
      mask |= (1 << u);
    }
    return true;
  }
};

#endif
