#include "common.h"

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        Value v1(a), v2(b);
        return Value(v1.a * v2.a - v1.b * v2.b, v1.a * v2.b + v1.b * v2.a);
    }
private:
    struct Value {
        int a, b;
        Value(int a_, int b_) : a(a_), b(b_) {};
        Value(string s) {
            int i = 0;
            for (; s[i] != '+'; ++i);
            a = stoi(s.substr(0, i));
            b = stoi(s.substr(i + 1, s.size() - (i + 1) - 1));
        }
        operator string() {
            return to_string(a) + '+' + to_string(b) + 'i';
        }
    };
};

int main() {
  string a = "1+1i";
  string b = "1+1i";
  cout << Solution().complexNumberMultiply(a, b) << endl;
  return 0;
}
