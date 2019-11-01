#include "common.h"

class Solution {
public:
  //Insert one char from stringstream
  void Insert(char ch) {
    counts[ch] += 1;
    q.push(ch);
  }
  //return the first appearence once char in current stringstream
  char FirstAppearingOnce() {
    while (!q.empty()) {
      if (counts[q.front()] == 1) return q.front();
      q.pop();
    }
    return '#';
  }
private:
  map<char, int> counts;
  queue<char> q;
};

int main() {
  string s;
  Solution so;
  cin >> s;
  for (char c : s) {
    so.Insert(c);
  }
  cout << so.FirstAppearingOnce() << endl;
  return 0;
}
