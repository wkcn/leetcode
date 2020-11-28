// 注意, 要避免溢出
#include "common.h"


class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        /*
          F(0) =                       0 * a[0] + 1 * a[1] + 2 * a[2] + 3 * a[3]
          F(1) =            0 * a[3] + 1 * a[0] + 2 * a[1] + 3 * a[2]
          F(2) = 0 * a[2] + 1 * a[3] + 2 * a[0] + 3 * a[1]

          F(1) - F(0) = 0 * a[3] + 1 * a[0] + 1 * a[1] + 1 * a[2] - 3 * a[3]
          F(2) - F(1) = 0 * a[2] + 1 * a[3] + 1 * a[0] + 1 * a[1] - 3 * a[2]
         */
         using LL = long long;
         LL ans = 0;
         const int n = A.size();
         for (int i = 0; i < n; ++i) ans += i * A[i];
         LL su = accumulate(A.begin(), A.end(), (LL)0);
         LL co = ans;
         for (int i = 1; i < n; ++i) {
             // 注意这里是n
             // 而且n * A[n - i]要先转成LL, 否则乘法会溢出!
             co = co - n * (LL)A[n - i] + su;
             ans = max(ans, co);
         }
         return ans;
    }
};


int main() {
  // cout << sizeof(int) << ", " << sizeof(long) << ", " << sizeof(long long) << endl;
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().maxRotateFunction(A) << endl;
  return 0;
}
