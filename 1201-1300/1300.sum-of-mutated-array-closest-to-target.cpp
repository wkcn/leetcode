#include "common.h"


const int M = 100000;
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        /*
            [4, 9, 3], target = 10
            0: 0    0
            1: 3    0
            2: 6    0
            3: 9    0
            4: 11   1
            5: 12   3
            6: 13   5
            7: 14   7
            8: 15   9
            9: 16   11
         */
         array<int, M + 1> bins{0};
         for (int &x : arr) ++bins[x];
         array<int, M + 1> ps;
         ps[0] = 0;
         const int N = arr.size();
         int u = 0;
         for (int i = 1; i <= M; ++i) {
             ps[i] = ps[i - 1] + N - u;
             u += bins[i];
         }
         int p = lower_bound(ps.begin(), ps.end(), target) - ps.begin();
         // 3, 3, 3, 5
         // 注意有些重复的数字
         int pl = lower_bound(ps.begin(), ps.end(), ps[p-1]) - ps.begin(); 
         if (p == M + 1) return pl;
         return abs(ps[pl] - target) <= abs(ps[p] - target) ? pl : p;
    }
};

int main() {
  vector<int> arr; int target;
  INPUT_ARRAY(arr); cin >> target;
  cout << Solution().findBestValue(arr, target) << endl;
  return 0;
}
