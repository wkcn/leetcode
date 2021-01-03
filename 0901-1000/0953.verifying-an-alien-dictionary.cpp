#include "common.h"

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> ds;
        for (int i = 0; i < order.size(); ++i) {
            ds[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (!check(words[i - 1], words[i], ds)) {
                return false;
            }
        }
        return true;
    }
    bool check(string &a, string &b, array<int, 26> &ds) {
        // 注意字典序是怎么算的
        const int min_size = min(a.size(), b.size());
        for (int i = 0; i < min_size; ++i) {
            int d = ds[a[i] - 'a'] - ds[b[i] - 'a'];
            if (d != 0) return d < 0;
        }
        return a.size() <= b.size();
    }
};

int main() {
  vector<string> words = {"kuvp","q"};
  string order = "ngxlkthsjuoqcpavbfdermiywz";
  cout << Solution().isAlienSorted(words, order) << endl;
  return 0;
}
