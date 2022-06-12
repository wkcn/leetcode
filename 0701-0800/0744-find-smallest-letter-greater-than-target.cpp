#include "common.h"

template <typename Iter, typename T>
Iter my_upper_bound(Iter begin, Iter end, T value) {
  Iter lo = begin, hi = end;
  while (lo < hi) {
    const int len = distance(lo, hi);
    Iter mid = lo + len / 2;
    *mid <= value ? lo = mid + 1 : hi = mid;
  }
  return lo;
} 

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto p = my_upper_bound(letters.begin(), letters.end(), target);
        return p == letters.end() ? letters[0] : *p;
    }
};

int main() {
  vector<char> letters = {'c', 'f', 'j'};
  cout << Solution().nextGreatestLetter(letters, 'c') << endl;
  return 0;
}
