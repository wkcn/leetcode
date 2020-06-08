// TODO: 双向广度优先遍历
#include "common.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      if (wordList.empty()) return {};
      int target;
      // 循环里不要写int target!!!
      for (target = 0; target < wordList.size(); ++target) {
        if (wordList[target] == endWord) break;
      }
      if (target >= wordList.size()) return {};
      wordList.push_back(beginWord);
      int start = wordList.size() - 1;
      unordered_map<int, vector<int> > G;
      for (int i = 0; i < wordList.size(); ++i) {
        for (int j = i + 1; j < wordList.size(); ++j) {
          string &si = wordList[i];
          string &sj = wordList[j];
          int diff = 0;
          if (si.size() != sj.size()) continue;
          for (int k = 0; k < si.size(); ++k) {
            if (si[k] != sj[k]) ++diff;
          }
          if (diff == 1) {
            G[i].push_back(j);
            G[j].push_back(i);
          }
        }
      }
      vector<bool> vis(wordList.size(), false);
      vector<set<int> > last(wordList.size());
      vis[start] = true;
      queue<int> q;
      q.push(start);
      bool found = false;
      while (!q.empty()) {
        int size = q.size();
        vector<pair<int, int> > go_rec;
        while (size--) {
          int t = q.front(); q.pop();
          if (t == target) {
            found = true;
            break;
          }
          for (int &u : G[t]) {
            if (vis[u]) continue;
            go_rec.push_back({t, u}); // t -> u
            q.push(u);
          }
        }
        if (found) break;
        for (auto &p : go_rec) {
          vis[p.second] = true;
          last[p.second].insert(p.first);
        }
      }
      if (!found) return {};
      vector<vector<string> > ans;
      if (last[target].empty()) return {};
      vector<int> buf;
      function<void(int)> F;
      F = [&](int t) {
        if (last[t].empty()) {
          vector<string> a;
          for (int i = buf.size() - 1; i >= 0; --i) {
            a.push_back(wordList[buf[i]]);
          }
          a.push_back(endWord);
          ans.emplace_back(move(a));
          return;
        }
        for (const int &y : last[t]) {
          buf.push_back(y);
          F(y);
          buf.pop_back();
        } 
      };
      F(target);
      return ans;
  }
};

int main() {
  string beginWord, endWord;
  vector<string> wordList;
  cin >> beginWord >> endWord;
  INPUT_ARRAY(wordList);
  PRINT_ARRAY2D(Solution().findLadders(beginWord, endWord, wordList));
  return 0;
}
