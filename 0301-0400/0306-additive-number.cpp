#include "common.h"

string add_num(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string c;
  int i = 0, j = 0;
  int carry = 0;
  while (i < a.size() || j < b.size()) {
    if (i < a.size())
      carry += (a[i++] - '0');
    if (j < b.size())
      carry += (b[j++] - '0');
    c += (carry % 10) + '0';
    carry /= 10;
  }
  if (carry > 0) c += '1';
  reverse(c.begin(), c.end());
  return c;
}

bool check(const string &num, int e, int i, int j) {
  if (j == num.size()) return true;
  string r = add_num(num.substr(e, i - e), num.substr(i, j - i));
  for (int i = 0, k = j; i < r.size(); ++i, ++k) {
    if (k >= num.size()) return false;
    if (r[i] != num[k]) return false;
  }
  int end = j + r.size();
  return check(num, i, j, end);
} 

class Solution {
public:
    bool isAdditiveNumber(string num) {
      const int n = num.size();
      for (int i = 1; i < n - 1; ++i) {
        if (num[0] == '0' && (i - 0 > 1)) break;
        for (int j = i + 1; j < n; ++j) {
          // [0, i), [i, j)
          if (num[i] == '0' && (j - i > 1)) break;
          if (check(num, 0, i, j)) return true;
        }
      }
      return false;
    }
};

int main() {
  while (1) {
    string num; cin >> num;
    cout << Solution().isAdditiveNumber(num) << endl;
  }
  while (1) {
    string a; cin >> a;
    string b; cin >> b;
    cout << add_num(a, b) << endl;
  }
  return 0;
}
