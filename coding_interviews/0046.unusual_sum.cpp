#include "common.h"

// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#define SOLUTION 3

#if SOLUTION == 0
class Solution {
public:
  int Sum_Solution(int n) {
    int ans = 0;
    n && (ans = Sum_Solution(n - 1) + n);
    return ans;
  }
};
#elif SOLUTION == 1

// if x is odd, return 0xFFFFFFFF, otherwise 0
#define F(x) (((x & 1) << 31) >> 31)
class Solution {
public:
  int Sum_Solution(int n) {
    int a = n + 1, b = n, s = 0;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;

    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;

    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;

    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    s += a & F(b); a<<=1; b>>=1;
    return s >> 1;
  }
};

#elif SOLUTION == 2

class Helper {
public:
  Helper() {
    su += n++;
  }
  static void reset() {
    n = 1;
    su = 0;
  }
  static int get_sum() {
    return su;
  }
private:
  static int n;
  static int su;
};

int Helper::n = 1;
int Helper::su = 0;

class Solution {
public:
  int Sum_Solution(int n) {
    Helper *p = new Helper[n];
    delete []p;
    int su = Helper::get_sum();
    Helper::reset();
    return su;
  }
};

#elif SOLUTION == 3

// 注意加virtual声明是虚函数！
class Base {
public:
  virtual int Sum(int) {return 0;}
  virtual ~Base() {}
};

Base* arr[2];

class Derived : public Base {
public:
  int Sum(int n) {
    return arr[!!n]->Sum(n-1) + n;
  }
  ~Derived() {}
};

class Solution {
public:
  int Sum_Solution(int n) {
    arr[0] = new Base();
    arr[1] = new Derived();
    int su = arr[1]->Sum(n);
    delete arr[0];
    delete arr[1];
    return su;
  }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().Sum_Solution(n) << endl;
  return 0;
}
