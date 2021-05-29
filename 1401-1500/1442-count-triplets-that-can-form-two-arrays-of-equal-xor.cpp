#include "common.h"

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // 如果a == b, 那么a ^ b = 0
        // a[i] ^ ... ^ a[j] ^ ... ^ a[k] = 0, i < j <= k, 至少两元素
        if (arr.size() < 2) return 0;
        unordered_map<int, int> cnts;
        int ans = 0;
        int x = arr[0];
        cnts[0] = 1;
        cnts[x] = 1;
        for (int k = 1; k < arr.size(); ++k) {
            x ^= arr[k]; // [0, k] and k >= 1
            cout << x << endl;
            /*
             * if exists i < k and c[0, i - 1] ^ c[0, k] == 0
             */
            ans += cnts[x]++;
        }
        return ans;
    }
};

int main() {
  vector<int> arr{2, 3, 1, 6, 7};
  cout << Solution().countTriplets(arr) << endl;
  return 0;
}
