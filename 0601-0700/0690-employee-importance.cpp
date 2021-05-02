#include "common.h"

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      unordered_map<int, Employee*> ems;
      for (Employee* e : employees) {
        ems[e->id] = e;
      }
      set<int> used;
      queue<int> q;
      used.insert(id);
      q.push(id);
      int ans = 0;
      while (!q.empty()) {
        int id = q.front(); q.pop();
        Employee *e = ems[id];
        ans += e->importance; 
        for (int u : e->subordinates) {
          if (used.insert(u).second) {
            q.push(u);
          }
        }
      }
      return ans;
    }
};

int main() {
  return 0;
}
