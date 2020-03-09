#include "common.h"


const string NUMBERS[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const string UNITS[3] = {"Thousand", "Million", "Billion"};
const string TENS[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string MTENS[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string numberToWords(int num) {
      if (num == 0) return "Zero";
      stack<string> st;
      int level = -1;
      while (num > 0) {
        int y = num % 1000;
        num /= 1000;
        int hundred = y / 100;
        int lower2 = y % 100;
        if (lower2 < 10) {
          if (lower2 > 0)
            st.push(NUMBERS[lower2]);
        } else if (lower2 >= 10 && lower2 < 20) {
          st.push(TENS[lower2 - 10]);
        } else {
          if (lower2 % 10 > 0)
            st.push(NUMBERS[lower2 % 10]);
          st.push(MTENS[lower2 / 10]);
        }
        if (hundred >= 1) {
          st.push("Hundred");
          st.push(NUMBERS[hundred]);
        }
        st.push("|"); // 结束符号
        ++level;
      }
      string ans;
      bool first = true;
      bool valid = false;
      while (!st.empty()) {
        if (st.top()[0] == '|') {
          if (valid) {
            ans += ' ';
            ans += UNITS[level]; 
            valid = false;
          }
          --level;
        } else {
          if (!first) ans += ' ';
          first = false;
          ans += st.top();
          valid = true;
        }
        st.pop();
      }
      return ans;
    }
};


int main() {
  int num;
  cin >> num;
  cout << Solution().numberToWords(num) << endl;
  return 0;
}
