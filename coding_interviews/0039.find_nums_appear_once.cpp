#include "common.h"

// 位运算的优先级&比==低!!!
class Solution {
public:
  void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int v = 0;
    for (int e : data) v ^= e;
    int ind = 1;
    while ((v & ind) == 0) ind <<= 1;
    *num1 = 0; *num2 = 0;
    for (int e : data) (e & ind) ? *num2 ^= e : *num1 ^= e;
  }
};

int main() {
  vector<int> data;
  INPUT_ARRAY(data);
  int num1, num2;
  Solution().FindNumsAppearOnce(data, &num1, &num2);
  cout << num1 << ", " << num2 << endl;
  return 0;
}
