#include "common.h"


const string units[] = {"Thousand", "Million", "Billion"};
const string tys[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six",\
                       "Seven", "Eight", "Nine"};
const string tens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        stack<string> st;
        int u = -1;
        while (num > 0) {
            int t = num % 1000;
            if (t > 0 && u >= 0) st.push(units[u]);
            int g = t % 100;
            if (g >= 10 && g < 20) {
                st.push(tens[g - 10]);
            } else {
                if (g % 10 > 0) st.push(ones[g % 10]);
                if (g / 10 > 0) st.push(tys[g / 10]);
            }
            t /= 100;
            if (t > 0) {
                st.push("Hundred");
                st.push(ones[t]);
            }
            ++u;
            num /= 1000;
        }
        string ans;
        while (!st.empty()) {
            if (!ans.empty()) ans += ' ';
            ans += st.top(); st.pop();
        }
        return ans;
    }
};


int main() {
  while (1) {
    int i;
    cin >> i;
    cout << Solution().numberToWords(i) << endl;
  }
  return 0;
}
