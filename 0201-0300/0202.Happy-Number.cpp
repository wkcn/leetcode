#include "common.h"

#if 0
class Solution {
public:
    bool isHappy(int n) {
      if (flags.find(n) != flags.end()) {
        int flag = flags[n];
        // for loop
        if (flag == GOING) return false;
        return flag;
      }

      flags[n] = GOING;

      int u = 0;
      int tmp = n;
      while (tmp > 0) {
        int k = tmp % 10;
        u += k * k;
        tmp /= 10;
      }
      if (u == 1) {
        flags[n] = HAPPY;
        return true;
      }
      if (isHappy(u)) {
        flags[n] = HAPPY;
        return true;
      }
      flags[n] = UNHAPPY;
      return false;
    }
private:
    static map<int, int> flags;
    enum Flag {
      GOING = -2,
      UNHAPPY = 0,
      HAPPY = 1,
    };
};
map<int, int> Solution::flags;
#else

#if 0
class Solution {
public:
    bool isHappy(int n) {
      if (n <= 0) return false;
      unordered_set<int> se;
      se.insert(n);
      int su, k;
      while (n != 1) {
        su = 0;
        while (n > 0) {
          k = n % 10;
          su += k * k;
          n /= 10;
        }
        n = su;
        if (se.find(n) != se.end()) return false;
        se.insert(n);
      }
      return true;
    }
};
#else

// check cycle 
// Reference: https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
class Solution {
public:
    bool isHappy(int n) {
      int slow = n, fast = n;
      do {
        slow = next(slow);
        fast = next(next(fast));
      } while (slow != fast);
      return slow == 1;
    }
private:
    int next(int n) {
      int su = 0, k;
      while (n > 0) {
        k = n % 10;
        su += k * k;
        n /= 10;
      }
      return su;
    }
};
#endif

#endif

int main() {
  int n;
  Solution so;
  while (1) {
    cin >> n;
    cout << so.isHappy(n) << endl;
  }
  return 0;
}
