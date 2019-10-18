#include "common.h"

#if 0
class Solution {
public:
	void replaceSpace(char *str,int length) {
    queue<char> q;
    int i;
    for (i = 0; i < length; ++i) {
      char &c = str[i];
      if (c != ' ') q.push(c);
      else {
        q.push('%');
        q.push('2');
        q.push('0');
      }
      str[i] = q.front(); q.pop(); 
    }
    while (!q.empty()) {
      str[i++] = q.front();
      q.pop();
    }
    str[i] = 0;
	}
};
#else

/* inverse
 * 运行时间：5ms
 * 占用内存：480k
 */
class Solution {
public:
	void replaceSpace(char *str,int length) {
    int space = 0;
    for (int i = 0; i < length; ++i) if (str[i] == ' ') ++space;
    const int size = length + space*2;
    str[size] = 0;
    int st = size - 1;
    for (int i = length-1; i >= 0; --i) {
      char &c = str[i];
      if (c != ' ') {
        str[st--] = c;
      } else {
        str[st--] = '0';
        str[st--] = '2';
        str[st--] = '%';
      }
    }
  }
};

#endif

int main() {
  string s;
  getline(cin, s);
  int length = s.size();
  int space = 0;
  for (char c : s) {
    if (c == ' ') ++space; 
  }
  char *p = new char[s.size()];
  memcpy(p, s.c_str(), s.size()+space);
  Solution().replaceSpace(p, length);
  cout << p << endl;
  delete p;
  return 0;
}
