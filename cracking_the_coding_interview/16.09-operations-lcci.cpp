#include "common.h"


typedef unsigned long long ULL;
bool inited = false;
array<ULL, 32> ones; // binary: 1, 10, 100, 1000
array<ULL, 32> masks; // binary: 1, 11, 111, 1111
array<ULL, 32> prefix_ones; // binary: 0xFFFF, 0xFFFE, 0xFFFC, 0xFFF8, 0xFFF0 ...

array<ULL, 32> ones_inv; // binary: 0x80 00 00 00
array<ULL, 32> masks_inv;

class Operations {
public:
    Operations() {
      if (!inited) {
        inited = true;
        ULL su = 1;
        ULL one = 1;
        int i;
        int j = 31;
        for (i = 0; i < 32; ++i) {
          ones[i] = one;
          masks[i] = su;
          ones_inv[j] = one;
          masks_inv[j] = su;
          j = minus_one(j);
          one += one;
          su += one;
        }
        su = 0;
        for (j = 31; j >= 0; j = minus_one(j)) {
          su += ones[j];
          prefix_ones[j] = su;
        }
      }
    }

    int minus(int a, int b) {
      ULL au = a;
      au += unary_minus(b);
      return au;
    }

    int multiply(int a, int b) {
      // 总不会两个INT32_MIN无穷吧~
      if (b == INT32_MIN) return multiply(b, a);
      bool m = b < 0;
      if (m)
        b = unary_minus(b);
      array<bool, 32> bits = get_reverse_bits(b);
      int ans = 0;
      for (int i = 0, j = 0; i < 31; ++i) {
        if (bits[i]) {
          while (j < i) {
              a += a;
              ++j;
          }
          ans += a;
        }
      }
      return m ? unary_minus(ans) : ans;
    }

    int divide(int a, int b) {
      // 用负数表达范围更广
      bool m = true;
      if (b > 0) {
        b = unary_minus(b);
      } else {
        m = !m;
      }
      if (a > 0) {
        a = unary_minus(a);
      } else {
        m = !m;
      }
      if (a > b) return 0;
      stack<pair<int, int> > st; // (除数，商)
      st.push({b, -1});
      while (1) {
        auto &p = st.top();
        ULL t = p.first;
        t += t;
        if (a <= t) {
          st.push({t, p.second+p.second});
        } else {
          break;
        }
      }
      int ans = 0;
      while (!st.empty()) {
        auto p = st.top(); st.pop();
        if (a <= p.first) {
          ans += p.second;
          a = minus(a, p.first);
        }
      }
      return m ? unary_minus(ans) : ans;
    }

public:
    inline int minus_one(int value) {
      return (ULL)value + 0xFFFFFFFF;
    }
    inline int minus_bit(int value, int b) {
      return (ULL)value + prefix_ones[b];
    }
    inline int inv(int value) {
      ULL flag = value;
      ULL ans = 0;
      for (int i = 31; i >= 0; i = minus_one(i)) {
        if (flag >= ones[i]) {
          // 1 -> 0
          flag = minus_bit(flag, i);
        } else {
          ans += ones[i];
        }
      }
      return ans;
    }
    inline int unary_minus(int value) {
      return ULL(inv(value)) + 1;
    }
    inline int left_shift(int value, int b) {
      array<bool, 32> bits = get_bits(value);
      int ans = 0;
      int i, j;
      for (i = 0, j = b; j < 32; ++i, ++j) {
        if (bits[i]) ans += ones[j];
      }
      return ans;
    }
    inline int right_shift(int value, int b) {
      array<bool, 32> bits = get_bits(value);
      int ans = 0;
      int i, j;
      for (i = b, j = 0; i < 32; ++i, ++j) {
        if (bits[i]) ans += ones[j];
      }
      if (bits[31] && j < 32) {
        ans += masks_inv[j];
      }
      return ans;
    }
    array<bool, 32> get_bits(int value) {
      array<bool, 32> ans;
      ULL flag = value;
      for (int i = 31; i >= 0; i = minus_one(i)) {
        if (flag >= ones[i]) {
          flag = minus_bit(flag, i);
          ans[i] = true;
        } else {
          ans[i] = false;
        }
      }
      return ans;
    }
    array<bool, 32> get_reverse_bits(int value) {
      array<bool, 32> bits = get_bits(value);
      for (int i = 0, j = 31; i < 32; ++i, j = minus_one(j)) {
        swap(bits[i], bits[j]);
      }
      return bits;
    }
};


int main() {
  Operations op;
  while (1) {
    int a, b;
    cin >> a >> b;
    cout << "a - b = " << op.minus(a, b) << endl;
    cout << "a * b = " << op.multiply(a, b) << endl;
    cout << "a / b = " << op.divide(a, b) << endl;
  }
  return 0;
}
