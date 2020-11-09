#include "common.h"

struct DNode {
    DNode *nodes[26]{nullptr};
    bool is_leaf = false;
    ~DNode () {
        for (DNode *r : nodes) delete r;
    }
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        unique_ptr<DNode> root(new DNode);
        for (string &s :words) {
            DNode *r = root.get();
            for (char &c : s) {
                DNode *& t = r->nodes[c - 'a'];
                if (!t) t = new DNode();
                r = t;
            }
            r->is_leaf = true;
        }

        sort(words.begin(), words.end(), [](string &a, string &b) {
            if (a.size() != b.size()) return b.size() < a.size();
            return a < b;
        });

        for (string &s : words) {
            queue<int> q;
            q.push(0);
            bool inited = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u >= s.size()) {
                    if (inited) continue;
                    return s;
                }
                DNode *r = root.get();
                for (; u < s.size(); ++u) {
                    int d = s[u] - 'a';
                    DNode *t = r->nodes[d];
                    if (!t) break;
                    if (t->is_leaf) {
                      // 注意, 要两个以上的单词组合
                      if (!inited || u + 1 < s.size())
                        q.push(u + 1);
                    }
                    r = t;
                }
                inited = false;
            }
        }

        return {};
    }
};

int main() {
  vector<string> words;
  INPUT_ARRAY(words);
  cout << Solution().longestWord(words) << endl;
  return 0;
}
