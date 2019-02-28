#include "common.h" 

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
      int v = 0;
      for (int &u : nums) {
        v ^= u;
      }
      return v;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      // 64 bits
      const int size = nums.size();
      if (size == 1) return nums[0];
      const int half = size >> 1;
      const void *ptr = &nums[0];
      const int64_t *pint64 = static_cast<const int64_t*>(ptr);
      int64_t v = pint64[0];
      for (int i = 1; i < half; ++i) {
        v ^= pint64[i];
      }
      int res = (v >> 32) ^ v;
      res ^= nums[size-1];
      return res;
    }
};

int main() {
  vector<int> nums;
  /*
  INPUT_ARRAY(nums);
  */
  const int N = 1000;
  const int K = rand() % N;
  for (int i = 0; i < N; ++i) {
    nums.push_back(i);
    if (K != i)
      nums.push_back(i);
  }
  std::shuffle(std::begin(nums), std::end(nums), std::default_random_engine(39));

  Timer timer;

  timer.tic();
  Solution so;
  cout << so.singleNumber(nums) << endl;
  timer.toc();

  timer.tic();
  Solution so2;
  cout << so2.singleNumber(nums) << endl;
  timer.toc();
  return 0;
}
