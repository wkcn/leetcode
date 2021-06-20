#include "common.h"

class ThroneInheritance {
public:
    ThroneInheritance(string kingName): kingName_(kingName) {
    }
    
    void birth(string parentName, string childName) {
      trees[parentName].push_back(childName);
    }
    
    void death(string name) {
      removed.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
      // DFS
      vector<string> ans;
      stack<string> st; st.push(kingName_);
      while (!st.empty()) {
        string s = move(st.top()); st.pop();
        if (removed.count(s) == 0)
          ans.push_back(s);
        auto &vs = trees[s];
        for (auto p = vs.rbegin(); p != vs.rend(); ++p) {
          st.push(*p);
        }
      }
      return ans;
    }
private:
    unordered_map<string, vector<string>> trees;
    unordered_set<string> removed;
    string kingName_;
};

int main() {
  ThroneInheritance t("king"); // 继承顺序：king
  t.birth("king", "andy"); // 继承顺序：king > andy
  t.birth("king", "bob"); // 继承顺序：king > andy > bob
  t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
  t.birth("andy", "matthew"); // 继承顺序：king > andy > matthew > bob > catherine
  t.birth("bob", "alex"); // 继承顺序：king > andy > matthew > bob > alex > catherine
  t.birth("bob", "asha"); // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
  PRINT_ARRAY(t.getInheritanceOrder()); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
  t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
  PRINT_ARRAY(t.getInheritanceOrder()); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]

  return 0;
}
