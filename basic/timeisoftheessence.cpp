/*
 *Time is of the Essence
Description

Do you know how long one million seconds is?  How about one billion seconds?  Well, the answer to the first one is

11 days, 13 hours, 46 minutes and 40 seconds

Accurate, but a little over-precise.  A more reasonable answer might be "11 days, 14 hours" or just "12 days" (after rounding).  As another example, if I asked how long three million inches were, you could approximate it by saying either "47 miles" or "47 miles, 613 yards".  This sort of imprecision is what we're looking for in this problem!


Input
Input consists of two lines. The first line has the form

n name_1 c_1 name_2 c_2 ...... name_{n-1} c_{n-1} name_n

Each name_i is a unit of measurement and each c_i is a conversion rate, telling you how many units of type name_{i+1} are in a unit of type name_i.  For example, in the first sample input, this line tells you that there are 24 hours in one day, 60 minutes in each hour and 60 seconds in each minute.  The value n indicates the total number of unit names and satisfies 2 <= n <= 10.  All names are alphabetic strings with no blanks and always specify the plural form of the unit (which you should use for output no matter the value is associated with the unit).  All conversion values are positive integers. Following this line is a single positive integer m <= 2,000,000,000 indicating an amount of the last unit (i.e., name_n).


Output
Display two lines.  The first line should give the closest conversion of the input amount to units specified by name_1, rounded to the nearest integer.  The second line should do the same, but be a bit more precise using the two largest units -- name_1 and name_2.  When rounding, always round up when the fraction is >= 0.5.  Note that there are no commas in the output.


Sample Input 1 

4 days 24 hours 60 minutes 60 seconds
1000000
Sample Output 1

12 days
11 days 14 hours
Sample Input 2 

5 years 365 days 24 hours 60 minutes 60 seconds
1000000000
Sample Output 2

32 years
31 years 259 days
 * 单位转换
 * 特殊样例：
 * 3 a 3 b 3 c
 * 5
 *
 * 3 h 60 m 60 s
 * 29*60+59
 *
 * 后面的数湊上来后可能就刚好进位了
 */
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;

ULL JW(ULL v, ULL z) {
  if (z % 2 == 0) return v >= (z / 2);
  return v > z / 2;
}

ULL JW(pair<ULL, ULL> p) {
  return JW(p.first, p.second);
}

int main() {
  while (1) {
  vector<pair<string, ULL> > vs;
  int un;
  ULL unit;
  string name;

  if (!(cin >> un) || un == 0) return 0;
  for (int i = 0; i < un; ++i) {
    if (i == 0) unit = 0;
    else cin >> unit;
    cin >> name;
    vs.push_back({name, unit});
  }

  ULL value;
  cin >> value;

  /*
   *
   * 20:29:50
   *
    3 a 3 b 3 c 
    5

fact: 0 a 1 b 2 c
   estimate: 1 a
             0 a 2 b

    3 a 3 b 3 c
    8
  fact: 0 a 2 b 2 c
        1 a
        1 a 0 b

      22:29:54
    estimate:
      22
      22:30
   */

  /*
  vector<pair<ULL, ULL> > rec; // value, div_number
  for (int i = vs.size()-1; i >= 1; --i) {
    ULL di = vs[i].second;
    ULL ys = value % di; 
    value /= di;
    rec.push_back({ys, di});
  }
  // value: name_1
  ULL value0, value1, value2;
  value0 = value + JW(rec.back());

  value2 = rec.back().first;
  if (rec.size() >= 2)
    value2 += JW(rec[rec.size()-2]);
  value1 = value + value2 / vs[1].second;
  value2 %= vs[1].second;
  */
  ULL d = 1;
  for (int i = 1; i < vs.size(); ++i) d *= vs[i].second;
  ULL value0 = value / d + JW(value % d, d);

  ULL e = 1; 
  ULL t = vs[1].second;
  for (int i = 2; i < vs.size(); ++i) e *= vs[i].second;
  ULL value2 = value / e + JW(value % e, e);
  ULL value1 = value2 / t; 
  value2 %= t;


  printf("%llu %s\n", value0, vs[0].first.c_str());
  printf("%llu %s %llu %s\n", value1, vs[0].first.c_str(), value2, vs[1].first.c_str());

  break;
  }
  return 0;
}
