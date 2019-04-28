#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
      return num1.size() > num2.size() ? multiply_in(num1, num2) : multiply_in(num2, num1);
    }
private:
    string multiply_in(string num1, string num2) {
      // num1.size() > num2.size()
      vector<int> a1, a2;
      str_to_vec(num1, a1);
      str_to_vec(num2, a2);
      vector<int> buf[10]; 
      buf[0] = {0};
      buf[1] = a1;
      for (int u : a2) {
        if (buf[u].size() == 0) {
          multiply_scalar(buf[u], a1, u);
        }
      }
      vector<int> res(a1.size() + a2.size(), 0);
      for (int i = 0; i < a2.size(); ++i) {
        vector<int> &m = buf[a2[i]];
        for (int j = 0; j < m.size(); ++j) {
          res[i+j] += m[j];
        }
      }
      int val = 0;
      for (int i = 0; i < res.size() - 1; ++i) {
        if (res[i] < 10) continue;
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
      }
      int left = res.size();
      while (--left >= 0 && res[left] == 0);
      if (left < 0) return "0";
      string res_str;
      for (;left >= 0;--left) res_str += res[left] + '0';
      return res_str;
    }
    void multiply_scalar(vector<int> &out, const vector<int> &in, int scalar) {
      out.resize(in.size());
      int val = 0;
      for (int i = 0; i < in.size(); ++i) {
        val += in[i] * scalar;
        out[i] = val % 10;
        val /= 10;
      }
      if (val > 0) out.push_back(val);
    }
    void str_to_vec(string &s, vector<int> &v) {
      v.resize(s.size());
      int i = 0;
      for_each(s.rbegin(), s.rend(), [&v, &i](char c){v[i++] = c - '0';}); 
    }
};

int main() {
  Solution so;
  while (1) {
    string n1, n2;
    cin >> n1 >> n2;
    cout << so.multiply(n1, n2) << endl;
  }
  return 0;
}
