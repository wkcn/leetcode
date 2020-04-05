#include "common.h"

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
      if (kv.count(key)) {
        return update(key).second;
      }
      return -1;
    }

    void put(int key, int value) {
      if (cap == 0) return;
      if (kv.count(key)) {
        update(key).second = value;
      } else {
        if (kv.size() >= cap) {
          auto &[freq, li] = *freq_link.begin();
          auto &r = li.front();
          int key = r.first;
          kv.erase(key);
          li.pop_front();
          if (li.size() == 0) freq_link.erase(freq_link.begin());
        }
        freq_link[0].push_back({key, value});
        kv[key] = {0, --freq_link[0].end()}; 
      }
    }
private:
    pair<int, int>& update(int key) {
        auto &[freq, it] = kv[key];
        freq_link[freq].erase(it);
        ++freq;
        auto &li = freq_link[freq];
        li.emplace_back(*it);
        it = --li.end();
        return *it; 
    }
private:
    int cap;
    map<int, std::list<pair<int, int>>> freq_link;
    unordered_map<int, pair<int, std::list<pair<int, int>>::iterator>> kv;  
};

int main() {
  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  return 0;
}
