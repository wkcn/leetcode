#include "common.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty()) return {};
        vector<string> ans;

        int i = 0;
        while (i < words.size()) {
            int len = words[i].size();
            int j = i + 1;
            for (; j < words.size(); ++j) {
                if (len + words[j].size() + j - i > maxWidth) break;
                len += words[j].size();
            }
            if (j - i == 1) {
                ans.push_back(words[i] + string(maxWidth - len, ' '));
            } else {
                if (j < words.size()) {
                    int space = maxWidth - len;
                    ans.push_back(words[i]);
                    int g = j - i - 1;
                    int h = space / g;
                    int y = space % g;
                    int t = 0;
                    for (int k = i + 1; k < j; ++k) {
                        ans.back() += string(h + (t < y), ' ');
                        ans.back() += words[k];
                        ++t;
                    }
                } else {
                    // the last line
                    ans.push_back(words[i]);
                    for (int k = i + 1; k < j; ++k) {
                        ans.back() += ' ';
                        ans.back() += words[k];
                    }
                    ans.back() += string(maxWidth - ans.back().size(), ' ');
                }
            }
            i = j;
        }
        return ans;
    }
};

int main() {
  vector<string> a = {"This", "is", "an", "example", "of", "text", "justification."};
  int b = 16;
  for (string &s : Solution().fullJustify(a, b)) {
    cout << s << ": " << s.size() << endl;
  }
  return 0;
}
