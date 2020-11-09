#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        const int len = A.size();
        if (len < 3) return false;
        if (A[0] >= A[1]) return false;
        bool inc = true;
        for (int i = 1; i < len - 1; ++i) {
            if (A[i] > A[i + 1]) {
                if (inc) inc = false;
            } else {
                if (A[i] < A[i + 1]) {
                    if (!inc) {
                      return false;
                    }
                } else return false;
            }
        }
        return !inc;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        const int len = A.size();
        int i = 0;
        while (i < len - 1 && A[i] < A[i+1]) ++i;
        if (i == 0 || i == len - 1) return false;
        while (i < len - 1 && A[i] > A[i+1]) ++i;
        return i == len - 1;
    }
};

#endif

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().validMountainArray(A) << endl;
  return 0;
}
