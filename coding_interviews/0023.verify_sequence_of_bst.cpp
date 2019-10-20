#include "common.h"

// notice: empty sequence
class Solution {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty()) return false;
    return sub_verify(sequence, 0, sequence.size());
  }
private:
  bool sub_verify(vector<int> &sequence, int start, int end) {
    if (end - start <= 1) return true;
    int v = sequence[end-1];
    int lend = end - 2;
    while (lend >= 0 && sequence[lend] > v) --lend;
    for (int i = start; i < lend; ++i) if (sequence[i] > v) return false;
    return sub_verify(sequence, start, lend+1) && sub_verify(sequence, lend+1, end-1);
  }
};

int main() {
  vector<int> sequence;
  INPUT_ARRAY(sequence);
  cout << Solution().VerifySquenceOfBST(sequence) << endl;
  return 0;
}
