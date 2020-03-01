// TODO: 双指针方法能够更简练
class Solution {
public:
    string compressString(string S) {
      char r;
      int cnt = 0;
      string R;
      for (char c : S) {
        if (c == r) ++cnt;
        else {
          if (cnt > 0) {
            R += r;
            R += to_string(cnt);
          }
          r = c; 
          cnt = 1;
        }
      }
      if (cnt > 0) {
          R += r;
          R += to_string(cnt);
      }
      return R.size() < S.size() ? R : S;
    }
};
