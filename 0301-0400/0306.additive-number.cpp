#include "common.h"

// 下标0存最低位会好很多！
class LargeInt {
public:
  LargeInt() {}
  explicit LargeInt(int num) {
    for (char c : to_string(num)) {
      data.push_back(c - '0');
    }
  }
public:
  friend ostream& operator<<(ostream &os, const LargeInt &);
  friend LargeInt& operator+=(LargeInt &a, const int &b);
  friend LargeInt& operator*=(LargeInt &a, const int &b);
  friend LargeInt& operator+=(LargeInt &a, const LargeInt &b);
  friend LargeInt operator+(const LargeInt &a, const LargeInt &b);
  friend bool operator<(const LargeInt &a, const LargeInt &b);
  friend bool operator>(const LargeInt &a, const LargeInt &b);
  friend bool operator==(const LargeInt &a, const LargeInt &b);
  friend bool operator!=(const LargeInt &a, const LargeInt &b);
private:
  vector<int> data;
};

ostream& operator<<(ostream &os, const LargeInt &a) {
  for (int x : a.data) {
    os << x;
  }
  return os;
}

LargeInt& operator+=(LargeInt &a, const int &b) {
  a += LargeInt(b);
  return a;
}
LargeInt& operator*=(LargeInt &a, const int &b) {
  vector<int> data;
  int carry = 0;
  for (int j = (int)a.data.size() - 1; j >= 0; --j) {
    carry += a.data[j] * b;
    data.push_back(carry % 10);
    carry /= 10;
  }
  while (carry > 0) {
    data.push_back(carry % 10);
    carry /= 10;
  }
  reverse(data.begin(), data.end());
  a.data = move(data);
  return a;
}
LargeInt& operator+=(LargeInt &a, const LargeInt &b) {
  vector<int> data;
  int i = a.data.size() - 1, j = b.data.size() - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry > 0) {
    if (i >= 0) carry += a.data[i--];
    if (j >= 0) carry += b.data[j--];
    data.push_back(carry % 10);
    carry /= 10;
  }
  reverse(data.begin(), data.end());
  a.data = move(data);
  return a;
}
LargeInt operator+(const LargeInt &a, const LargeInt &b) {
  LargeInt c = a;
  c += b;
  return c;
}
bool operator<(const LargeInt &a, const LargeInt &b) {
  if (a.data.size() != b.data.size()) return a.data.size() < b.data.size();
  for (int i = 0; i < a.data.size(); ++i) {
    if (a.data[i] != b.data[i]) return a.data[i] < b.data[i];
  }
  return false;
}
bool operator>(const LargeInt &a, const LargeInt &b) {
  return !(a < b || a == b);
}
bool operator==(const LargeInt &a, const LargeInt &b) {
  return a.data == b.data;
}
bool operator!=(const LargeInt &a, const LargeInt &b) {
  return !(a == b);
}

class Solution {
public:
    // 遇到true就可以退出了
    bool isAdditiveNumber(string S) {
      vector<LargeInt> vs;
      function<bool(int)> F = [&](int start) {
        if (start >= S.size()) return vs.size() >= 3;
        if (S[start] == '0') {
          if (vs.size() >= 2 && vs[vs.size() - 2] + vs.back() != LargeInt(0)) {
            return false;
          }
          vs.push_back(LargeInt(0));
          if (F(start + 1)) return true;
          vs.pop_back();
          return false;
        }
        LargeInt v(0);
        for (int i = start; i < S.size(); ++i) {
          v *= 10;
          v += S[i] - '0';
          if (vs.size() >= 2) {
            LargeInt su = vs[vs.size() - 2] + vs.back();
            if (v > su) break;
            if (v < su) continue;
          }
          vs.push_back(v);
          if (F(i + 1)) return true;
          vs.pop_back();
        }
        return false;
      };
      bool res = F(0);
      return res;
    }
};

int main() {
  string S;
  cin >> S;
  cout << Solution().isAdditiveNumber(S) << endl;
  return 0;
}
