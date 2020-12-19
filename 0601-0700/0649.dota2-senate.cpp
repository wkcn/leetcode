#include "common.h"

#if 0
class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0, d = 0;
        int tot_r = 0, tot_d = 0;
        for (char c : senate)
            if (c == 'R') ++tot_r;
            else ++tot_d;
        while (tot_r > 0 && tot_d > 0) {
            string t;
            for (char c : senate) {
                if (c == 'R') {
                    if (r > 0) {
                        --tot_r;
                        --r;
                        continue;
                    }
                    ++d;
                    t += c;
                } else {
                    if (d > 0) {
                        --tot_d;
                        --d;
                        continue;
                    }
                    ++r;
                    t += c;
                }
            }
            senate = move(t);
            cout << senate << endl;
        }
        return tot_r > 0 ? "Radiant" : "Dire";
    }
};
#else
class Solution {
public:
    string predictPartyVictory(string senate) {
        int tot_r = 0, tot_d = 0;
        int q = 0;
        for (char c : senate)
            if (c == 'R') ++tot_r;
            else ++tot_d;
        while (tot_r > 0 && tot_d > 0) {
            string t;
            for (char c : senate) {
                if (c == 'R') {
                    if (q < 0) {
                        --tot_r;
                    } else {
                        t += c;
                    }
                    ++q;
                } else {
                    if (q > 0) {
                        --tot_d;
                    } else {
                        t += c;
                    }
                    --q;
                }
            }
            senate = move(t);
        }
        return tot_r > 0 ? "Radiant" : "Dire";
    }
};
#endif

int main() {
  string s; cin >> s;
  cout << Solution().predictPartyVictory(s) << endl;
  return 0;
}
