#include "common.h"

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() : gen(rd()) {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
      auto &&x = v2i[val];
      bool ret = x.empty();
      const int ind = size(x);
      i2v.emplace_back(val, ind);
      x.push_back(size(i2v) - 1);
      return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
      auto &&x = v2i[val];
      if (x.empty()) return false;
      const int ind = x.back(); x.pop_back(); // 已经从v2i[val]中删除
      auto [v, i] = i2v[ind] = i2v.back();
      i2v.pop_back();  // 即使只有一个元素, 也能解决问题
      if (i < v2i[v].size()) // v2i[v]和x不一定是同一个 
        v2i[v][i] = ind;
      return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
      std::uniform_int_distribution<> dis(0, size(i2v) - 1);
      return i2v[dis(gen)].first;
    }
private:
    random_device rd;
    mt19937 gen;
    vector<pair<int, int> > i2v; // [(val, index in v2i), ...]
    unordered_map<int, vector<int> > v2i; // val -> index in i2v
};

int main() {
  RandomizedCollection rc;
  rc.insert(0);
  rc.insert(1);
  rc.remove(0);
  rc.insert(2);
  rc.remove(1);
  cout << rc.getRandom() << endl;
  return 0;
}
