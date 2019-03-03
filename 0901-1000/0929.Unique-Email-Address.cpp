#include "common.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
      set<string> vs;
      for (string& s : emails) {
        vs.insert(_get_valid_name(s));
      }
      return vs.size();
    }
private:
    string _get_valid_name(string s) {
      string v;
      int i;
      for (i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '+') {
          while (s[++i] != '@'){};
          break;
        } else if (c == '@') {
          break;
        } else {
          if (c != '.') v += c;
        }
      }
      v.append(s.substr(i, s.size()));
      return v;
    }
};

int main() {
  int n;
  cin >> n;
  vector<string> vs;
  string s;
  while(n--) {
    cin >> s;
    vs.push_back(s);
  }
  Solution so;
  cout << so.numUniqueEmails(vs) << endl;
  return 0;
}
