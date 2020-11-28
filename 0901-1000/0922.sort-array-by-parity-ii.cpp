#include "common.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.empty()) return {};
        const int n = A.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
          while (i < n && !(A[i] & 1)) i += 2;
          while (j < n && (A[j] & 1)) j += 2;
          if (i < n && j < n) swap(A[i], A[j]);
        }
        return A;
    }
};

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  PRINT_ARRAY(Solution().sortArrayByParityII(A));
  return 0;
}
