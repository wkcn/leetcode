class Solution {
public:
  bool canPermutePalindrome(string s) {
    bool flags[256];
    memset(flags, 0, sizeof(flags));
    for (char c: s) {
      flags[c] = !flags[c];
    }
    bool t = false;
    for (int i = 0; i < 256; ++i) {
      if (flags[i]) {
        if (t) return false;
        t = true;
      }
    }
    return true;
  }
};
