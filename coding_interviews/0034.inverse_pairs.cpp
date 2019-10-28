#include "common.h"

class Solution {
public:
  int InversePairs(vector<int> data) {
    int count = 0;
    merge_sort(data, 0, data.size(), count);
    return count;
  }
private:
  void merge_sort(vector<int>& data, int start, int end, int& count) {
    if (end - start <= 1) return;
    int mid = start + (end - start) / 2;
    merge_sort(data, start, mid, count);
    merge_sort(data, mid, end, count);
    vector<int> buf(data.begin() + start, data.begin() + mid);
    int l_len = mid - start;
    int i = 0, j = mid;
    int k = start;
    while (i < l_len || j < end) {
      while (i < l_len && (j >= end || buf[i] <= data[j])) data[k++] = buf[i++];
      while (j < end && (i >= l_len || buf[i] > data[j])) {
        if (i < l_len) count = (count + l_len - i) % 1000000007;
        data[k++] = data[j++];
      }
    }
  }
};

int main() {
  vector<int> data;
  INPUT_ARRAY(data);
  cout << Solution().InversePairs(data) << endl;
  return 0;
}
