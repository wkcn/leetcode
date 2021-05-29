#include "common.h"

class Solution {
  public:
    string intToRoman(int num) {
      string ans;
      int i = 0;
      while (num > 0) {
        int v = num % 10;
        // units[i] and units[i + 1] 
        if (v <= 3) ans += string(v, units[i]);
        else if (v == 4) {
          ans += units[i + 1];
          ans += units[i];
        } else if (v == 9) {
          ans += units[i + 2];
          ans += units[i];
        } else {
          ans += string(v - 5, units[i]);
          ans += units[i + 1];
        }
        i += 2;
        num /= 10; 
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
  private:
    static constexpr const char* units = "IVXLCDM";
};

int main() {
  vector<int> nums = {3, 4, 9, 58, 1994};
  for (int x : nums) {
    cout << x << ": " << Solution().intToRoman(x) << endl;
  }
  return 0;
}
