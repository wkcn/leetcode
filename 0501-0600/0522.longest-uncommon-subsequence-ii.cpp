#include "common.h"

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // 不是最长的序列，也可能被选到
        sort(strs.begin(), strs.end(), [](string &a, string &b) {return a.size() > b.size();});
        for (int i = 0; i < strs.size(); ++i) {
            bool fail = false;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (IsSub(strs[i], strs[j])) {
                    fail = true;
                    break;
                }
            }
            if (!fail) return strs[i].size();
        }
        return -1;
    }
private:
    bool IsSub(string &a, string &b) {
        if (a.size() > b.size()) return false;
        int j, i = 0;
        for (int j = 0; j < b.size() && i < a.size(); ++j) {
          if (b[j] == a[i]) ++i;
        }
        return i >= a.size();
    }
};

int main() {
  vector<string> vs;
  INPUT_ARRAY(vs);
  cout << Solution().findLUSlength(vs) << endl;
  return 0;
}
