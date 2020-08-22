#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
      if (num1 == "0" || num2 == "0") return "0";
      vector<int> v1 = get_vec(num1);
      vector<int> v2 = get_vec(num2);
      array<vector<int>, 10> buf;
      // 注意字符串的resize和构造函数
      vector<int> v3(num1.size() + num2.size(), 0);
      for (int j = 0; j < v2.size(); ++j) {
        int b = v2[j];
        if (b == 0) continue;
        vector<int> &res = buf[b];
        if (res.empty()) {
          res = v1;
          for_each(res.begin(), res.end(), [&](int &x) {x *= b;});
        }
        for (int i = 0; i < v1.size(); ++i) {
          v3[i + j] += res[i];
        }
      }
      int carry = 0;
      for (int i = 0; i < v3.size(); ++i) {
        v3[i] += carry;
        carry = v3[i] / 10;
        v3[i] %= 10;
      }
      int z = v3.size() - 1;
      while (v3[z] == 0) --z;
      string out;
      out.resize(z + 1);
      // i的顺序!!
      for (int i = z; i >= 0; --i) {
        out[z - i] = v3[i] + '0'; 
      }
      return out;
    }
    vector<int> get_vec(const string &s) {
      vector<int> v(s.size());
      const int len = s.size();
      for (int i = 0; i < len; ++i) v[len - 1 - i] = s[i] - '0';
      return v;
    }
};

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << Solution().multiply(num1, num2) << endl;
  return 0;
}
