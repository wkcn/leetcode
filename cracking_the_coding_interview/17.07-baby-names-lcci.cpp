#include "common.h"

class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
      unordered_map<string, int> ma;
      unordered_map<string, string> parents;
      for (string &s : names) {
        auto p = ReadName(s);
        ma.insert(p);
      }
      for (string &s : synonyms) {
        auto [a, b] = ReadSyn(s);
        string pa = GetParent(parents, a);
        string pb = GetParent(parents, b);
        // 注意判断父亲相同时
        if (pa == pb) continue;
        if (pa > pb) {
          swap(pa, pb);
          swap(a, b); // 要一起换
        }
        parents[pb] = pa;
        auto tb = ma.find(pb);  // 这里应该是找b存不存在!
        if (tb != ma.end()) {
          ma[pa] += tb->second;
          ma.erase(tb);
        }
      }
      vector<string> ans;
      for (auto &p : ma) {
        stringstream ss;
        ss << p.first << '(' << p.second << ')';
        ans.emplace_back(ss.str());
      }
      return ans;
    }
    string GetParent(unordered_map<string, string> &parents, string a) {
      auto p = parents.find(a);
      if (p == parents.end()) {
        return a;
      }
      return p->second = GetParent(parents, p->second);
    }
    pair<string, int> ReadName(const string &s) {
        int i = 0;
        while (s[i] != '(') ++i;
        string name = s.substr(0, i);
        ++i;
        int v = 0;
        for (; s[i] != ')'; ++i) {
            v = v * 10 + (s[i] - '0');
        }
        return {name, v};
    }
    pair<string, string> ReadSyn(const string &s) {
        int i = 0;
        while (s[i] != ',') ++i;
        return {s.substr(1, i - 1), s.substr(i + 1, s.size() - 1 - (i+1))};
    }
};

int main() {
  /*
  vector<string> names;
  vector<string> synonyms;
  INPUT_ARRAY(names);
  INPUT_ARRAY(synonyms);
  */
  vector<string> names = {"John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"};
  vector<string> synonyms = {"(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"};
  PRINT_ARRAY(Solution().trulyMostPopular(names, synonyms));
  return 0;
}
