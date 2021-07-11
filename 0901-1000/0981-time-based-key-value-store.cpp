#include "common.h"

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
      ma[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
      auto p = ma.find(key);
      if (p == ma.end()) return "";
      auto r = upper_bound(p->second.begin(), p->second.end(), timestamp,
          [](int val, pair<int, string> &a){
            return val < a.first;
          }
      );
      if (r == p->second.begin()) return ""; 
      return (--r)->second;
    }
private:
    unordered_map<string, vector<pair<int, string>> > ma;
};

int main() {
  TimeMap kv;
  kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1  
  cout << kv.get("foo", 1) << endl;  // 输出 "bar"  
  cout << kv.get("foo", 3) << endl; // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）  
  kv.set("foo", "bar2", 4);
  cout << kv.get("foo", 4) << endl; // 输出 "bar2"  
  cout << kv.get("foo", 5) << endl; // 输出 "bar2"  
  return 0;
}
