// 要注意类型转换！！
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
struct Person {
    int start, end;
    bool operator<(const Person &p) {
        return start < p.start;
    }
};

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<Person> vs;
        const int n = birth.size();
        for (int i = 0; i < n; ++i) {
            vs.push_back(Person{birth[i], death[i]});
        }
        sort(vs.begin(), vs.end());
        priority_queue<int, vector<int>, greater<int> > q;
        int best = -1;
        int bestYear;
        for (int i = 0; i < n; ++i) {
            int year = vs[i].start;
            q.push(vs[i].end);
            while (!q.empty() && q.top() < year) {
                q.pop();
            }
            // 注意这里！！！
            if (int(q.size()) > best) {
                best = q.size();
                bestYear = year;
            }
        }
        return bestYear;
    }
};

#elif SOLUTION == 2
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        array<int, 101> born{0}, dead{0};
        const int n = birth.size();
        for (int i = 0; i < n; ++i) {
            ++born[birth[i] - 1900];
            ++dead[death[i] - 1900];
        }
        int best = born[0];
        int cnt = born[0];
        int bestYear = 1900;
        for (int i = 1; i <= 100; ++i) {
            cnt += born[i] - dead[i-1];
            if (cnt > best) {
                best = cnt;
                bestYear = 1900 + i;
            }
        }
        return bestYear;
    }
};
#elif SOLUTION == 3
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        array<int, 102> p{0};
        const int n = birth.size();
        for (int i = 0; i < n; ++i) {
            ++p[birth[i] - 1900];
            --p[death[i] - 1900 + 1];
        }
        int best = birth[0];
        int bestYear = 1900;
        // p is delta, not the number of person
        int cur = birth[0];
        for (int i = 1; i <= 100; ++i) {
            cur += p[i];
            if (cur > best) {
                best = cur;
                bestYear = 1900 + i;
            }
        }
        return bestYear;
    }
};
#endif

int main() {
  // 注意类型转换！！！
  /*
   * 如果某个运算符的运算对象不一致，这些运算对象将转换成同一种类型。但是如果某个运算对象的类型是无符号类型，那么转换的结果就要依赖机器中各个整数类型中各个整数类型的相对大小了。

像往常一样，首先执行整型提升。如果结果的类型匹配，无需进行进一步的转换。如果两个（提升后的）运算对象的类型要么都是带符号的、要么都是无符号的，则小类型的运算对象转换成较大的类型。

如果一个运算对象是无符号类型、另外一个运算对象是带符号类型，而且其中的无符号类型不小于带符号类型，那么带符号的运算对象转换成无符号的。如上面的程序中的unsigned int和int，则int类型的运算对象转换成unsigned int类型。如果int型的值恰好为负值，则转换为unsigned int的数值总数去模后的余数。也就造成了a < b的奇怪情况。
Reference: https://www.jb51.net/article/181253.htm
例如，8比特大小的unsigned char可以表示0至255区间内的值，如果我们赋了一个区间以外的值，则实际的结果是该值对256取模后所得的余数。因此把-1赋给8比特大小的unsigned char所得的结果是255。

剩下的一种情况是带符号类型大于无符号类型，此时转换的结果依赖于机器，如果无符号类型的所有值都能存在在该带符号类型中，则无符号类型的运算对象转换成带符号类型。如果不能，那么带符号类型的运算对象转换成无符号类型。
   */
  unsigned int a = 30;
  int b = -1;
  // 4294967265
  cout << b - a << endl;

  vector<int> birth, death;
  INPUT_ARRAY(birth); INPUT_ARRAY(death);
  cout << Solution().maxAliveYear(birth, death) << endl;
  return 0;
}
