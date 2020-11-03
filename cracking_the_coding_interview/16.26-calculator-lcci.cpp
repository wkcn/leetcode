// TODO: 简化, 逆波兰表达式
#include "common.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int p = 0;
        auto read_num = [&]() -> int {
            int v = 0;
            while (p < s.size()) {
                if (isdigit(s[p])) {
                    v = v * 10 + (s[p] - '0');
                    ++p;
                } else break;
            }
            return v;
        };
        while (p < s.size()) {
            while (p < s.size() && s[p] == ' ') ++p;
            if (p >= s.size()) break;
            if (isdigit(s[p])) {
                int v = read_num();
                if (!ops.empty()) {
                    if (ops.top() == '*') {
                        v *= nums.top();
                        nums.pop();
                        ops.pop();
                    } else if (ops.top() == '/') {
                        v = nums.top() / v;
                        nums.pop();
                        ops.pop();
                    }
                }
                nums.push(v);
            } else {
                // op
                char op = s[p];
                ops.push(op);
                ++p;
            }
        }
        int res = 0;
        while (!ops.empty()) {
            if (ops.top() == '+') {
                res += nums.top();
            } else {
                res -= nums.top();
            }
            nums.pop();
            ops.pop();
        }
        res += nums.top();
        return res;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().calculate(s) << endl;
  return 0;
}
