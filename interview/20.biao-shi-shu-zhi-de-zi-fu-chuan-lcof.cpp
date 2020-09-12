#include "common.h"

// 这个可以进一步优化, 比如根据字符就能知道状态, 设定终结节点, 结尾时判断即可
class Solution {
public:
    bool isNumber(string s) {
        // 是数字: 3.
        // 不是数字: .
        // 起始状态: 0 -> (1, 2, 9)
        // +/-: 1 -> (2, 9)
        // digit1: 2 -> (2, 3, 5, 8)
        // .: 3 -> (4, 5, 8) // 后面可以没有数字
        // digit2: 4 -> (4, 5, 8)
        // e/E: 5 -> (6, 7)
        // +/-: 6 -> (7)
        // digit3: 7 -> (7, 8)
        // end: 8
        // .: 3 -> (4) // 后面必须有数字 
        const vector<vector<int>> sparse = {
          {1, 2, 9},
          {2, 9},
          {2, 3, 5, 8},
          {4, 5, 8},
          {4, 5, 8},
          {6, 7},
          {7},
          {7, 8},
          {8},
          {4},
        };
        const vector<function<bool(char)> > func = {
          [](char c) {return false;},
          [](char c) {return c == '+' || c == '-';},
          [](char c) {return isdigit(c);},
          [](char c) {return c == '.';},
          [](char c) {return isdigit(c);},
          [](char c) {return c == 'e' || c == 'E';},
          [](char c) {return c == '+' || c == '-';},
          [](char c) {return isdigit(c);},
          [](char c) {return false;},
          [](char c) {return c == '.';},
        };
        int state = 0;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        for (char c : s) {
          bool pass = false;
          for (int next: sparse[state]) {
            if (func[next](c)) {
              pass = true;
              state = next;
              break;
            }
          }
          if (!pass) return false;
          cout << "STATE: " << state << endl;
        }
        for (int next: sparse[state]) {
          if (next == 8) return true;
        }
        return false;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().isNumber(s) << endl;
  return 0;
}
