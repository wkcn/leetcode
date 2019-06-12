#include "common.h"

class Solution {
  public:
    string shiftingLetters(string S, vector<int>& shifts) {
      vector<int> su(shifts.size());
      su.back() = shifts.back();
      for (int i = shifts.size()-2; i >= 0; --i) {
        su[i] = (su[i + 1] + shifts[i]) % 26;
      }
      for (int i = 0; i < S.size(); ++i) {
        S[i] = (S[i] - 'a' + su[i]) % 26 + 'a';
      }
      return S;
    }
};

int main() {
  string S;
  cin >> S;
  vector<int> shifts;
  INPUT_ARRAY(shifts);

  cout << Solution().shiftingLetters(S, shifts) << endl;
  return 0;
}
