#include "common.h"

#define SOLUTION 3
#if SOLUTION == 1
// 1256 ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (n == 0) return 0;
        unordered_map<string, int> s2i;
        for (int i = 0; i < wordList.size(); ++i) {
            s2i[wordList[i]] = i;
        }
        auto sp = s2i.find(beginWord);
        int start_i;
        // 坑, beginWord有可能在, 也有可能不在wordList里
        if (sp == s2i.end()) {
            wordList.push_back(beginWord);
            s2i[beginWord] = n;
            start_i = n;
            ++n;
        } else {
            start_i = sp->second;
        }
        auto ep = s2i.find(endWord);
        if (ep == s2i.end()) return 0;
        const int end_i = ep->second;

        vector<vector<int> > G(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (connect(wordList[i], wordList[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        queue<int> q;
        q.push(start_i);;
        vector<bool> vis(n, false);
        vis[start_i] = true;
        int step = 1;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                int r = q.front(); q.pop();
                if (r == end_i) {
                    // 要return而不是break!
                    return step;
                }
                for (int t : G[r]) {
                    if (!vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
            ++step;
        }
        return 0;
    }
    bool connect(string &a, string &b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int k = 0; k < a.size(); ++k) {
            if (a[k] != b[k]) ++diff;
        }
        return diff == 1;
    }
};

#elif SOLUTION == 2
// 120 ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (n == 0) return 0;
        unordered_map<string, int> s2i;
        for (int i = 0; i < wordList.size(); ++i) {
            s2i[wordList[i]] = i;
        }
        auto sp = s2i.find(beginWord);
        int start_i;
        // 坑, beginWord有可能在, 也有可能不在wordList里
        if (sp == s2i.end()) {
            wordList.push_back(beginWord);
            s2i[beginWord] = n;
            start_i = n;
            ++n;
        } else {
            start_i = sp->second;
        }
        auto ep = s2i.find(endWord);
        if (ep == s2i.end()) return 0;
        const int end_i = ep->second;

        vector<vector<int> > G(n);
        unordered_map<string, vector<int> > v2i; // 虚拟节点
        for (int i = 0; i < n; ++i) {
            string &s = wordList[i];
            for (int k = 0; k < s.size(); ++k) {
                char c = s[k];
                s[k] = '*';
                vector<int> &vs = v2i[s];
                for (int t : vs) {
                    G[i].push_back(t);
                    G[t].push_back(i);
                }
                vs.push_back(i);
                s[k] = c;
            }
        }

        queue<int> q;
        q.push(start_i);;
        vector<bool> vis(n, false);
        vis[start_i] = true;
        int step = 1;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                int r = q.front(); q.pop();
                if (r == end_i) {
                    // 要return而不是break!
                    return step;
                }
                for (int t : G[r]) {
                    if (!vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
            ++step;
        }
        return 0;
    }
};

#elif SOLUTION == 3

// 124 ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (n == 0) return 0;
        unordered_map<string, int> s2i;
        for (int i = 0; i < wordList.size(); ++i) {
            s2i[wordList[i]] = i;
        }
        auto sp = s2i.find(beginWord);
        int start_i;
        // 坑, beginWord有可能在, 也有可能不在wordList里
        if (sp == s2i.end()) {
            wordList.push_back(beginWord);
            s2i[beginWord] = n;
            start_i = n;
            ++n;
        } else {
            start_i = sp->second;
        }
        auto ep = s2i.find(endWord);
        if (ep == s2i.end()) return 0;
        const int end_i = ep->second;

        vector<vector<int> > G(n);
        unordered_map<string, vector<int> > v2i; // 虚拟节点
        for (int i = 0; i < n; ++i) {
            string &s = wordList[i];
            for (int k = 0; k < s.size(); ++k) {
                char c = s[k];
                s[k] = '*';
                vector<int> &vs = v2i[s];
                for (int t : vs) {
                    G[i].push_back(t);
                    G[t].push_back(i);
                }
                vs.push_back(i);
                s[k] = c;
            }
        }

        queue<int> q1, q2;
        q1.push(start_i);
        q2.push(end_i);
        vector<int> vis(n, 0);
        vis[start_i] = 1;
        vis[end_i] = 2;
        int step = 2;
        auto go = [&](queue<int> &q, const int flag) -> bool {
            int qsize = q.size();
            while (qsize--) {
                int r = q.front(); q.pop();
                const int other_flag = 3 - flag;
                // if (vis[r] == other_flag) return true;
                for (int t : G[r]) {
                    int &u = vis[t];
                    if (u == 0) {
                        u = flag;
                        q.push(t);
                    } else if (u == other_flag) {
                        return true;
                    }
                }
            }
            return false;
        };
        while (!q1.empty() && !q2.empty()) {
            if (go(q1, 1)) return step;
            ++step;
            if (go(q2, 2)) return step;
            ++step;
        }
        return 0;
    }
};

#endif

int main() {
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> vs = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << Solution().ladderLength(beginWord, endWord, vs) << endl;
  return 0;
}
