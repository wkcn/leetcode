// TODO: 进一步优化
#include "common.h"

// 要初始化啊
struct DNode {
    DNode *nodes[26]{nullptr};
    bool is_leaf{false};
    int leaf_id{-1};
};

class Solution {
public:
  vector<string> maxRectangle(vector<string>& words) {
    /*
     * 这里的words是假设能构成一个矩阵的, 假设矩阵大小为R * C
     * 那么: R + C >= words.size()
     * C 是最长的字符串长度
     * R 是可变的
     */
    sort(words.begin(), words.end());
    words.resize(unique(words.begin(), words.end()) - words.begin());
    int C = 0;
    for (string &s : words) {
      C = max(C, (int)s.size());
    }

    int rest = words.size();
    vector<DNode*> nodes(rest);
    DNode root;
    // 只需要给竖着的单词建立字典树
    for (int i = 0; i < words.size(); ++i) {
      string &s = words[i];
      DNode *r = &root;
      for (char c : s) {
        DNode *& t = r->nodes[c - 'a'];
        if (!t) t = new DNode();
        r = t;
      }
      r->is_leaf = true;
      r->leaf_id = i;
      nodes[i] = r;
    }

    vector<int> buf;
    vector<int> ans;

    function<void(const vector<int> &, vector<DNode*> &)> go;
    go = [&](const vector<int> &vs, vector<DNode*> &roots) {
      const int slen = words[vs[0]].size();
      if (ans.size() >= C || buf.size() >= C) return;
      for (int u : vs) {
        string &s = words[u];
        bool fail = false;
        for (int i = 0; i < s.size(); ++i) {
          char c = s[i];
          DNode *t = roots[i]->nodes[c - 'a'];
          if (!t) {
            fail = true;
            break;
          }
        }
        if (fail) continue;

        vector<DNode*> roots_bak = roots;
        vector<int> leaves;
        if (nodes[u]->is_leaf) {
          leaves.push_back(u);
          nodes[u]->is_leaf = false;
          --rest;
        }

        int roots_leaves = 0;
        for (int i = 0; i < s.size(); ++i) {
          char c = s[i];
          roots[i] = roots[i]->nodes[c - 'a'];
          if (roots[i]->is_leaf) {
            leaves.push_back(roots[i]->leaf_id);
            --rest;
            roots[i]->is_leaf = false;
          }
          if (roots[i]->leaf_id != -1) ++roots_leaves;
        }

        buf.push_back(u);
        if (roots_leaves == roots.size()) {
          if (ans.empty() || buf.size() * slen > ans.size() * words[ans[0]].size()) ans = buf;
        }
        go(vs, roots);
        buf.pop_back();

        for (int u : leaves) {
          if (!nodes[u]->is_leaf) {
            nodes[u]->is_leaf = true;
            ++rest;
          }
        }

        roots = roots_bak;
      }
    };

    unordered_map<int, vector<int> > groups;
    for (int i = 0; i < words.size(); ++i) {
      groups[words[i].size()].push_back(i);
    }
    for (auto &g : groups) {
      vector<DNode*> roots(g.first, &root);
      go(g.second, roots);
    }


    vector<string> anss;
    for (int i : ans) {
      anss.push_back(words[i]);
    }
    return anss;

  }
};

int main() {
  /*
  vector<string> words = {"this", "real", "hard", "trh", "hea", "iar", "sld"};
  PRINT_ARRAY(Solution().maxRectangle(words));

  vector<string> words2 = {"aa"};
  PRINT_ARRAY(Solution().maxRectangle(words2));

  vector<string> words3 = {"eat", "tea", "tan", "ate", "nat", "bat"};
  PRINT_ARRAY(Solution().maxRectangle(words3));
  */

  vector<string> words4 = {"lcauj", "mdlby", "myulp", "yvkqn", "usajk", "rpj", "bojvf", "ukmkb", "afqbhs", "j", "ebe", "yacov", "wsaep", "zdk", "wziqrdd", "pcjfn", "nlrehaq", "dasrc", "lruvq", "dvca"};
  PRINT_ARRAY(Solution().maxRectangle(words4));
  return 0;
}
