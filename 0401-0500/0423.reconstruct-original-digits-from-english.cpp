// 找规律, 看看哪些字母是独占的, 依次计数, 记得初始化
#include "common.h"


class Solution {
    vector<string> vs = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    vector<pair<char, int> > ma = {
        {'z', 0},
        {'w', 2},
        {'x', 6},
        {'g', 8},
        {'s', 7},
        {'t', 3},
        {'v', 5},
        {'r', 4},
        {'i', 9},
        {'o', 1}
    };
public:
    string originalDigits(string s) {
        /*
            zero: z
            two: w
            six: x
            eight: g

            6 -> seven: s
            8 -> three: t
            7 -> five: v

            8 -> four: r

            5 -> nine: i

            other -> one: o
         */
        array<int, 26> cnts{0};
        for (char c : s) ++cnts[c - 'a'];
        string ans;
        for (pair<char, int> &p : ma) {
            Count(ans, cnts, p.second, cnts[p.first - 'a']);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    void Count(string &ans, array<int, 26> &cnts, int num, int cnt) {
        if (cnt == 0) return;
        for (char c : vs[num]) {
            cnts[c - 'a'] -= cnt;
        }
        ans += string(cnt, '0' + num);
    }
};


int main() {
  string s;
  cin >> s;
  cout << Solution().originalDigits(s) << endl;
  return 0;
}
