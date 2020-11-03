// TODO: 双向BFS
#include "common.h"

class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int target = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                target = i;
                break;
            }
        }
        if (beginWord == endWord) return {beginWord};
        if (target == -1) return {};
        wordList.push_back(beginWord);
        const int n = wordList.size();
        vector<vector<int> > G(n);
        for (int i = 0; i < n; ++i) {
            string &a = wordList[i];
            for (int j = i + 1; j < n; ++j) {
                string &b = wordList[j];
                if (a.size() != b.size()) continue;
                int diff = 0;
                for (int k = 0; k < a.size(); ++k) {
                    if (a[k] != b[k]) ++diff;
                }
                if (diff == 1) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int cur = n - 1;
        vector<int> last(n, -1);
        last[cur] = -2;
        queue<int> q;
        q.push(cur);
        int step = 1;
        bool found = false;
        while (!q.empty()) {
            const int len = q.size();
            for (int w = 0; w < len; ++w) {
                cur = q.front(); q.pop();
                if (cur == target) {
                  found = true;
                  break;
                }
                for (int t : G[cur]) {
                    if (last[t] == -1) {
                        last[t] = cur;
                        q.push(t);
                    }
                }
            }
            if (found) break;
            ++step;
        }
        if (last[target] == -1) return {};
        vector<string> ans(step);
        while (target != -2) {
            ans[--step] = wordList[target];
            target = last[target];
        }
        return ans;
    }
};

int main() {
  string beginWord;
  string endWord;
  vector<string> wordList;
  cin >> beginWord >> endWord;
  INPUT_ARRAY(wordList);
  PRINT_ARRAY(Solution().findLadders(beginWord, endWord, wordList));
  return 0;
}
