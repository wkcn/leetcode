// TODO: 进一步的优化
#if SOLUTION == 1
struct MyNode {
    int key;
    int value;
    MyNode *left, *right;
    MyNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {

    }
};

class MyDList {
public:
    MyDList() : head(-1, -1), tail(-1, -1) {
        head.right = &tail;
        tail.left = &head;
    }
    void insert(MyNode *pos, MyNode *r) {
        // insert before pos
        r->left = pos->left;
        r->right = pos;
        pos->left->right = r;
        pos->left = r;
    }
    void push_back(MyNode *r) {
        insert(&tail, r);
    }
    bool empty() {
        return head.right == &tail;
    }
    MyNode *pop_front() {
        MyNode *r = head.right;
        erase(r);
        return r;
    }
    MyNode *front() {
        return head.right;
    }
    void erase(MyNode *r) {
        r->left->right = r->right;
        r->right->left = r->left;
    }
private:
    MyNode head, tail;
};

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
      if (kv.count(key)) {
        return update(key)->value;
      }
      return -1;
    }

    void put(int key, int value) {
      if (cap == 0) return;
      if (kv.count(key)) {
        update(key)->value = value;
      } else {
        if (kv.size() >= cap) {
          auto &[freq, li] = *freq_link.begin();
          MyNode *r = li.front();
          int key = r->key;
          kv.erase(key);
          li.pop_front();
          if (li.empty()) freq_link.erase(freq_link.begin());
        }
        MyNode *u = new MyNode(key, value);
        freq_link[0].push_back(u);
        kv[key] = {0, u}; 
      }
    }
private:
    MyNode* update(int key) {
        auto &[freq, it] = kv[key];
        freq_link[freq].erase(it);
        if (freq_link[freq].empty()) {
            freq_link.erase(freq);
        }
        ++freq;
        auto &li = freq_link[freq];
        li.push_back(it);
        return it;
    }
private:
    int cap;
    map<int, MyDList> freq_link;
    unordered_map<int, pair<int, MyNode*>> kv;  
};
#elif SOLUTION == 2

// 注意什么时候删除链表，以及元素erase后不能再用迭代器访问

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
        pair<int, int> p = *it;
        freq_link[freq].erase(it);
        if (freq_link[freq].empty()) freq_link.erase(freq);
        ++freq;
        auto &li = freq_link[freq];
        li.emplace_back(p);
        it = --li.end();
        return *it; 
    }
private:
    int cap;
    map<int, std::list<pair<int, int>>> freq_link;
    unordered_map<int, pair<int, std::list<pair<int, int>>::iterator>> kv;  
};

#elif SOLUTION == 3

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity), min_freq(0) {
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
          auto &li = freq_link[min_freq];
          auto &r = li.front();
          int key = r.first;
          kv.erase(key);
          li.pop_front();
          if (li.size() == 0) freq_link.erase(min_freq);
        }
        freq_link[0].push_back({key, value});
        min_freq = 0;
        kv[key] = {0, --freq_link[0].end()};
      }
    }
private:
    pair<int, int>& update(int key) {
        auto &[freq, it] = kv[key];
        pair<int, int> p = *it;
        freq_link[freq].erase(it);
        if (freq_link[freq].empty()) {
            freq_link.erase(freq);
            if (freq == min_freq) ++min_freq;
        }
        ++freq;
        auto &li = freq_link[freq];
        li.emplace_back(p);
        it = --li.end();
        return *it;
    }
private:
    int cap;
    int min_freq;
    unordered_map<int, std::list<pair<int, int>>> freq_link;
    unordered_map<int, pair<int, std::list<pair<int, int>>::iterator>> kv;
};

#endif
