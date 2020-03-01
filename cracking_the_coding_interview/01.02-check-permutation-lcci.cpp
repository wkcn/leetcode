class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
      if (s1.size() != s2.size()) return false;
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      // 其实return s1 == s2;就好了哈哈
      const int len = s1.size();
      for (int i = 0; i < len; ++i) {
        if (s1[i] != s2[i]) return false;
      } 
      return true;
    }
};
