#include "common.h"

class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), [](const int& a, const int& b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb < sb + sa;
    });
    string s;
    for (int v : numbers) {
      s += to_string(v);
    }
    return s;
  }
};

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  cout << Solution().PrintMinNumber(vs) << endl;
  return 0;
}
