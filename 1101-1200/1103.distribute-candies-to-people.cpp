#include "common.h"

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // 1  ,   2,   3, ..., n
        // n+1, n+2, n+3, ..., 2n
        // 2n+1, 2n+2, 2n+3, ..., 3n
        // 3n+1, 3n+2, 3n+4, ..., 4n

        // K*(K+1) / 2 <= CANDIES < (K+2)*(K+1) / 2
        // K(K+1) <= 2CANDIES < (K+2)(K+1)
        // 使用放缩法
        // K^2 < K(K+1) <= 2CANDIES < (K+2)(K+1) < (K+2)^2
        // 向下取整
        // K <= floor(sqrt(2*CANDIES)) < K+2
        // floor(sqrt(2*CANDIES))的候选值是K或K+1
        const int double_candies = candies << 1;
        int k = sqrti(double_candies); // 是k或k+1
        // 验证是K还是K+1
        // 假设是K+1
        if (k * (k+1)  > double_candies || (k+2)*(k+1) <= double_candies) --k;
        const int g = k / num_people;
        const int y = k % num_people;
        vector<int> ans(num_people);
        for (int i = 0; i < y; ++i) {
          ans[i] = ((i+1) + ((g)*num_people + i+1)) * (g+1) / 2;
        }
        for (int i = y; i < num_people; ++i) {
          ans[i] = ((i+1) + ((g-1)*num_people + i+1)) * (g) / 2;
        }
        ans[y] += candies - k * (k+1) / 2;

        return ans;
    }
    int sqrti(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int lo = 1, hi = n / 2 + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            mid <= n / mid ? lo = mid+1 : hi = mid;
        }
        return --lo;
    }
};

int main() {
  Solution so;
  int candies, num_people;
  cin >> candies >> num_people;
  PRINT_ARRAY(so.distributeCandies(candies, num_people));
  return 0;
}
