#include "common.h"

// TODO: 排列组合
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> rec(K, 0);
        rec[0] = 1;
        int su = 0;
        int ans = 0;
        for (int &x : A) {
            su += x;
            if (su < 0) su = (su % K + K) % K;
            else su %= K;
            ans += rec[su];
            rec[su] += 1;
        }
        return ans;
    }
};

int main() {
  vector<int> A;
  int k;
  INPUT_ARRAY(A);
  cin >> k;
  cout << Solution().subarraysDivByK(A, k) << endl;
  return 0;
}
