#include "common.h"
/*
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 */
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
      const int len = A.size();
      vector<int> b(len);
      b[0] = 1;
      for (int i = 1; i < len; ++i) {
        b[i] = b[i - 1] * A[i - 1];
      }
      int res = 1;
      for (int i = len - 2; i >= 0; --i) {
        res *= A[i + 1]; 
        b[i] *= res;
      }
      return b;
    }
};

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  PRINT_ARRAY(Solution().multiply(A));
  return 0;
}
