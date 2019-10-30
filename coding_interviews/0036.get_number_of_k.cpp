#include "common.h"

int lower_bound(vector<int> &data, int k) {
  // the first element in the range [first,last) which does not compare less than val.
  int len = data.size();
  int i = 0, j = len;
  while (i < j) {
    int mid = i + (j - i) / 2;
    data[mid] < k ? i = mid+1 : j = mid;
    // < k | k <=
  }
  return i;
}

int upper_bound(vector<int> &data, int k) {
  // the first element in the range [first,last) which compares greater than val.
  int len = data.size();
  int i = 0, j = len;
  while (i < j) {
    int mid = i + (j - i) / 2;
    data[mid] <= k ? i = mid+1 : j = mid;
    // <= k | k <
  }
  return i;
}

class Solution {
public:
  int GetNumberOfK(vector<int> data ,int k) {
    // 1, 2, 2, 3
    // 1, 3, 3, 5
    return upper_bound(data, k) - lower_bound(data, k);
  }
};

int main() {
  vector<int> data;
  int k;
  INPUT_ARRAY(data);
  cin >> k;
  cout << Solution().GetNumberOfK(data, k) << endl;
  return 0;
}
